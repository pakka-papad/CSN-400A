#include "algo.cpp"
#include "test.cpp"

void print(const pair<Point,Point> &l){
	cout << "[" << "{" << l.first.x << "," << l.first.y << "} {" << l.second.x << "," << l.second.y << "}] ";
}

void print(const vector<pair<Point,Point>> &v){
	for(auto &x: v) print(x);
	cout << "\n\n";
}

int main(){
	int n, m;
	cin >> n >> m;
    // for(n = 1; n <= 30; n++){
    //     for(m = 1; m <= 30; m++){
    //         cout << n << " " << m;
            auto r = getAllPairs(n,m);
            print(r);
            // cout << "All pairs:\n";
            // print(r);
            // auto missingPairs = checkForMissingPairs(n,m,r);
            // cout << "\n";
            // if(missingPairs.size() == 0){
            //     cout << "No missing pairs\n";
            // } else {
            //     cout << "Missing pairs:\n";
            //     print(missingPairs);
            // }
            // auto duplicates = checkForDuplicatePairs(n,m,r);
            // cout << "\n";
            // if(duplicates.size() == 0){
            //     cout << "No duplicate pairs\n";
            // } else {
            //     cout << "Duplicate pairs:\n";
            //     for(auto &x: duplicates){
            //         print(x.first);
            //         cout << " <-> ";
            //         print(x.second);
            //         cout << "\n";
            //     }
            // }
            // if(missingPairs.size() != 0 || duplicates.size() != 0){
            //     cout << ": check";
            // }
    //         cout << endl;
    //     }
    // }
	
	return 0;
}
