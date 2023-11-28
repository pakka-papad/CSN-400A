#ifndef ALGO_CPP
#define ALGO_CPP

#include <bits/stdc++.h>
#include "point.cpp"
using namespace std;


vector<pair<Point,Point>> getAllPairs(int n, int m){
	vector<pair<Point,Point>> res;
	if(m != n){
		int last_r = (n-1)/2, last_c = (m-1)/2;
		for(int r1 = 0; r1 <= last_r; r1++){
			for(int c1 = 0; c1 <= last_c; c1++){
				// one chosen point
				Point p1(r1, c1);
				bool p1OnR = (n%2 == 1 && r1 == last_r);
				bool p1OnC = (m%2 == 1 && c1 == last_c);
				if(p1OnR && p1OnC) continue;

				if(p1OnR) {
					res.push_back({p1, reflectC(n, m, p1)});
				} else if (p1OnC) {
					res.push_back({p1, reflectR(n, m, p1)});
				} else {
					res.push_back({p1, reflectC(n, m, p1)});
					res.push_back({p1, reflectR(n, m, p1)});
					res.push_back({p1, reflectC(n, m, reflectR(n, m, p1))});
				}

				for(int r2 = r1; r2 <= last_r; r2++){
					for(int c2 = (r1 == r2 ? c1+1 : 0); c2 <= last_c; c2++){
						// two chosen point
						Point p2(r2, c2);
						bool p2OnR = (n%2 == 1 && r2 == last_r);
						bool p2OnC = (m%2 == 1 && c2 == last_c);

						if(p2OnR && p2OnC) {
							res.push_back({p1, p2});
							continue;
						}

						if(p1OnR && p2OnR){
							res.push_back({p1, p2});
							res.push_back({p1, reflectC(n, m, p2)});
						} else if(p1OnC && p2OnC){
							res.push_back({p1, p2});
							res.push_back({p1, reflectR(n, m, p2)});
						} else if(p1OnR && p2OnC){
							res.push_back({p1, p2});
						} else if(p1OnC && p2OnR){
							res.push_back({p1, p2});
						} else if(p1OnR){
							res.push_back({p1, p2});
							res.push_back({p1, reflectC(n, m, p2)});
						} else if(p1OnC){
							res.push_back({p1, p2});
							res.push_back({p1, reflectR(n, m, p2)});
						} else if(p2OnR){
							res.push_back({p1, p2});
							res.push_back({p1, reflectC(n, m, p2)});
						} else if(p2OnC){
							res.push_back({p1, p2});
							res.push_back({p1, reflectR(n, m, p2)});
						} else {
							res.push_back({p1, p2});
							res.push_back({p1, reflectR(n, m, p2)});
							res.push_back({p1, reflectC(n, m, p2)});
							res.push_back({p1, reflectC(n, m, reflectR(n, m, p2))});
						}
					}
				}
			}
		}
	} else {
		int last_r = (n-1)/2, last_c = (m-1)/2;
		for(int r1 = 0; r1 <= last_r; r1++){
			for(int c1 = 0; c1 <= r1; c1++){
				Point p1(r1, c1);
				bool p1OnR = (n%2 == 1 && r1 == last_r);
				bool p1OnD1 = (r1 == c1);

				if(p1OnR && p1OnD1) continue;

				if(p1OnR){
					res.push_back({p1, reflectD2(n, m, p1)});
					res.push_back({p1, reflectC(n, m, p1)});
				} else if(p1OnD1){
					res.push_back({p1, reflectR(n, m, p1)});
					res.push_back({p1, reflectD2(n, m, p1)});
				} else {
					res.push_back({p1, reflectR(n, m, p1)});
					res.push_back({p1, reflectD2(n, m, p1)});
					res.push_back({p1, reflectD1(n, m, reflectD2(n, m, p1))});
					res.push_back({p1, reflectC(n, m, p1)});
					res.push_back({p1, reflectD1(n, m, p1)});

					res.push_back({p1, reflectR(n, m, reflectD1(n, m, p1))});
				}

				for(int r2 = r1; r2 <= last_r; r2++){
					for(int c2 = (r1 == r2 ? c1+1 : 0); c2 <= r2; c2++){
						Point p2(r2, c2);

						bool p2OnR = (n%2 == 1 && r2 == last_r);
						bool p2OnD1 = (r2 == c2);

						if(p2OnR && p2OnD1){
							res.push_back({p1, p2});
							continue;
						}

						if(p1OnR && p2OnR){
							res.push_back({p1, p2});
							res.push_back({p1, reflectC(n, m, p2)});
							res.push_back({p1, reflectD2(n, m, p2)});
						} else if(p1OnD1 && p2OnD1){
							res.push_back({p1, p2});
							res.push_back({p1, reflectD2(n, m, p2)});
							res.push_back({p1, reflectR(n, m, p2)});
						} else if(p1OnR && p2OnD1){
							res.push_back({p1, p2});
							res.push_back({p1, reflectD2(n, m, p2)});
						} else if(p1OnD1 && p2OnR){
							res.push_back({p1, p2});
							res.push_back({p1, reflectD2(n, m, p2)});
						} else if(p1OnR){
							res.push_back({p1, p2});
							res.push_back({p1, reflectR(n, m, reflectD2(n, m, p2))});
							res.push_back({p1, reflectD2(n, m, p2)});
							res.push_back({p1, reflectD1(n, m, reflectD2(n, m, p2))});
						} else if(p1OnD1){
							res.push_back({p1, p2});
							res.push_back({p1, reflectR(n, m, p2)});
							res.push_back({p1, reflectD2(n, m, reflectR(n, m, p2))});
							res.push_back({p1, reflectD2(n, m, p2)});
						} else if(p2OnR){
							res.push_back({p1, p2});
							res.push_back({p1, reflectD2(n, m, p2)});
							res.push_back({p1, reflectC(n, m, p2)});
							res.push_back({p1, reflectD1(n, m, p2)});
						} else if(p2OnD1){
							res.push_back({p1, p2});
							res.push_back({p1, reflectR(n, m, p2)});
							res.push_back({p1, reflectD2(n, m, p2)});
							res.push_back({p1, reflectC(n, m, p2)});
						} else {
							res.push_back({p1, p2});
							res.push_back({p1, reflectR(n, m, p2)});
							res.push_back({p1, reflectD2(n, m, reflectR(n, m, p2))});
							res.push_back({p1, reflectD2(n, m, p2)});
							res.push_back({p1, reflectD1(n, m, reflectD2(n, m, p2))});
							res.push_back({p1, reflectC(n, m, p2)});
							res.push_back({p1, reflectD2(n, m, reflectC(n, m, p2))});
							res.push_back({p1, reflectD1(n, m, p2)});
						}
					}
				}
			}
		}
	}
	return res;
}

#endif