#include "point.cpp"

pair<Point,Point> reflectPairC(int n, int m, const pair<Point,Point> &l){
	return {reflectC(n,m,l.first), reflectC(n,m,l.second)};
}

pair<Point,Point> reflectPairR(int n, int m, const pair<Point,Point> &l){
	return {reflectR(n,m,l.first), reflectR(n,m,l.second)};
}

pair<Point,Point> reflectPairD1(int n, int m, const pair<Point,Point> &l){
	return {reflectD1(n,m,l.first), reflectD1(n,m,l.second)};
}

pair<Point,Point> reflectPairD2(int n, int m, const pair<Point,Point> &l){
	return {reflectD2(n,m,l.first), reflectD2(n,m,l.second)};
}

void generateAllPRefs(int n, int m, const pair<Point,Point> &p, vector<pair<Point,Point>> &temp){
    temp.clear();
    auto sr = reflectPairR(n,m,p);
    temp.push_back(p);
    temp.push_back(sr);
    temp.push_back(reflectPairC(n,m,p));
    temp.push_back(reflectPairC(n,m,sr));
    if(n == m){
        temp.push_back(reflectPairD1(n,m,p));
        temp.push_back(reflectPairD2(n,m,p));
        temp.push_back(reflectPairD1(n,m,sr));
        temp.push_back(reflectPairD2(n,m,sr));
    }
}

vector<pair<Point,Point>> checkForMissingPairs(int n, int m, const vector<pair<Point,Point>> &v){
	set<pair<Point,Point>> st;
	for(auto &x: v) st.insert(x);
	vector<pair<Point,Point>> res, temp;
	vector<Point> pts;
	for(int r = 0; r < n; r++){
		for(int c = 0; c < m; c++){
			pts.emplace_back(r,c);
		}
	}

	int tt = pts.size();
	for(int i = 0; i < tt; i++){
		for(int j = i+1; j < tt; j++){
			pair<Point,Point> s = {pts[i],pts[j]};
			if(s.first == s.second) continue;
            generateAllPRefs(n, m, s, temp);
			if(
				all_of(
					temp.begin(),
					temp.end(),
					[&](const pair<Point,Point> &p){ 
						pair<Point,Point> p2 = {p.second,p.first};
						return (st.count(p) == 0 && st.count(p2) == 0); 
					}
				)
			){
				res.push_back(s);
			}
		}
	}
	return res;
}

vector<pair<pair<Point,Point>,pair<Point,Point>>> 
    checkForDuplicatePairs(int n, int m, const vector<pair<Point,Point>> &v){
    vector<pair<pair<Point,Point>,pair<Point,Point>>> res;
    vector<pair<Point,Point>> temp;
    int k = v.size();
    for(int i = 0; i < k; i++){
        for(int j = i+1; j < k; j++){
            generateAllPRefs(n, m, v[i], temp);
            if(
                any_of(
                    temp.begin(),
                    temp.end(),
                    [&](const pair<Point,Point> &a){
                        return ((a.first == v[j].first && a.second == v[j].second) || 
                            (a.first == v[j].second && a.second == v[j].first));
                    }
                )
            ){
                res.push_back({v[i], v[j]});
            }
        }
    }
    return res;
}