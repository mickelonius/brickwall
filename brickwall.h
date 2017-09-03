//THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
//LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
//NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef BRICKWALL_H
#define BRICKWALL_H

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <cstdlib>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::pair;

class BrickLayer {
public:
	map<int, long long> buildWall(const int &wallWidth, const int &wallHeight, const vector<int> &brickSizes);
	
private:
	vector< map<int, int> > permsWithCracks;
	vector<vector<bool> > vv;
	vector<vector<bool> > isCompVec;

	int getBrickLayerPerms(const int &width, const vector<int> &brickSizes);

	void getPermVectors(int b, const vector< map<int, int> > &pWC, vector<bool> bitSet);

};


#endif