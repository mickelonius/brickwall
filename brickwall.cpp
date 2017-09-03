//THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
//LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
//NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "brickwall.h"

map<int, long long> BrickLayer::buildWall(const int &wallHeight, const int &wallWidth, const vector<int> &brickSizes) {
	
	// solve core subproblem first
	getBrickLayerPerms(wallWidth, brickSizes);
					
	long long totalPerms;
	int n = vv.size();
	vector<long long> currentSum(n, 0LL);
	vector<long long> currentConfig(n, 1LL);
	map<int, long long> wallPerms;
		
	wallPerms[1] = n;

	// foreach layer, compute dot product and propagate to next layer computation
	for (int layer = 2; layer <= wallHeight; ++layer) {

		// compatability matrix (isCompVec) multiplied by current set of permutations (currentConfig)
		for (int col = 0; col < n; ++col) {
			currentSum[col] = std::inner_product(isCompVec[col].begin(), isCompVec[col].end(), currentConfig.begin(), 0LL); //sum0;
		}
		currentConfig = vector<long long>(currentSum);
		totalPerms = std::accumulate(currentSum.begin(), currentSum.end(), 0LL);
			
		wallPerms[layer] = totalPerms;
	}

	return wallPerms;   
}


int BrickLayer::getBrickLayerPerms(const int &width, const vector<int> &brickSizes) {
	vector<int> perms = vector<int>(width + 1, 0);
	perms[0] = 1;
	
	// This is an accumulation in place, where we don't update a matrix, we actually
	// just keep adding to a vector.  This is basically using dynamic programming to 
	// solve not only the initial combinatorial problem (perms), but also the enumeration
	// of all the permutations (permsWithCracks)
	for(int b = 0; b <= width; ++b) {
		permsWithCracks.push_back(map<int, int>());

		for(const int &bSize : brickSizes) {
			if(b >= bSize) {	

				// getting to b from b-bSize represents a unique permutation
				perms[b] += perms[b - bSize];

				// before collapsing all the data into perms array,
				// build tree-like structure to use for enumerating unique 
				// vectors
				if(b-bSize >= 0 && perms[b-bSize] > 0) {
					permsWithCracks[b][b-bSize] = perms[b-bSize];
				}
			}			
		}
	}
	
	// get all permutation values from tree
	getPermVectors(width, permsWithCracks, vector<bool>(width, false));

	// create compatability matrix
	int n = perms[width];

	// pre-allocate "matrix"
	for(int i=0; i<n; ++i) {
		isCompVec.push_back(vector<bool>(n, false));
	}

	// matrix is symmetric... but there's gotta be a better way to do this
	for(int j=0; j<n; ++j) {			
		for(int k=j+1; k<n; ++k) {
			// really want to use a bitset<> or something more efficient here
			if(std::inner_product(vv[j].begin(), vv[j].end(), vv[k].begin(), 0) == 0) {
				isCompVec[k][j] = true;
				isCompVec[j][k] = true;
			}
		}
	}
	
	return n;	
}

// traverse "tree" built during permutation computation to enumerate where cracks are
void BrickLayer::getPermVectors(int b, const vector< map<int, int> > &pWC, vector<bool> bits) {
	for(const pair<int, int> &m : pWC[b]) {
		if(m.first > 0) {	
			vector<bool> tempBits(bits);
			tempBits[m.first-1] = true;
			getPermVectors(m.first, pWC, tempBits);
		}
		else if(m.first == 0) {
			vv.push_back(bits);
		}
	}
}