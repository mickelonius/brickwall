//THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
//LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
//NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "brickwall.h"

int main(int argc, char* argv[])
{	
	int height = std::atoi(argv[1]); //10;
	int width = std::atoi(argv[2]); //32;

	cout << height << "x" << width << " wall" << endl;

	vector<int> brickSizes;
	brickSizes.push_back(2);
	brickSizes.push_back(3);

	BrickLayer bLayer;
	map<int, long long> layers = bLayer.buildWall(height, width, brickSizes);
	
	cout << layers[height] << " ways to build a " << height << "x" << width << " wall" << endl;

	return 0;
}

