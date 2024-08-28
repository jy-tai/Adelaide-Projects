#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

#define INF 9999

// DEBUG print
void debugPrintVector (std::vector<int> *p, std::string info, int nV) {
	std::cout << info <<" DEBUG:" << std::endl;
	for (int i=0; i < nV; i++) {
		for (int j=0; j < nV; j++) {
			std::cout << p->at(i*nV+j);
			if (j+1 < nV) std::cout << ",";
		}
		std::cout << std::endl;
	}
}

// is cyclic check
bool isCyclicUtil (std::vector<int> *p, int u, int v, int w, int nV) {
	for (int k=0; k < nV; k++) {
		if (k == u) continue;
		if (k == w) continue; // origin - skip
		if (p->at(u * nV + k) != 1) continue;
		if (p->at(k * nV + v) != 1) {
//std::cout << "DEBUG2: u,v,k,w=" << u << "," <<v<<","<< k <<","<<w<< std::endl;
			if (isCyclicUtil(p, k, v, w, nV)) {
				return true;
			}
		}
		else {
//std::cout << "DEBUG2: rtn true" << std::endl;
			return true;;
		}
	}
//std::cout << "DEBUG2: rtn false" << std::endl;
	return false;
}
bool isCyclic (std::vector<int> *p, int u, int v, int nV, bool visited[]) {
	for (int k=0; k < nV; k++) {
		if (k == u) continue;
		if (k == v) continue;
		if (p->at(u * nV + k) != 1) continue;
		if(visited[k]) continue;
		visited[k]= true;
//std::cout << "DEBUG1: u,k,v=" << u << "," <<k<<","<< v << std::endl;
		if (p->at(k * nV + v) != 1) {
			if (isCyclic(p, k, v, nV, visited))
				return true;
		}
		else {
//std::cout << "DEBUG1: rtn true" << std::endl;
//std::cout << "visited:";
for (int j=0; j<nV; j++)
//std::cout << visited[j];
//std::cout << std::endl;
			return true;;
		}
	}
//std::cout << "DEBUG1: rtn false" << std::endl;
	return false;
}

// store input into array
void storeIn (std::vector<int> *p, std::string str1, int nV) {

	int j1=0, j2=0, val;

	do {
		if (str1[j2] != ',') {
			val = int(str1[j2]);
			if (val >= 91) val -= 71;
			else if (val >= 65) val -= 65;
			else val -= 48;
			p->push_back(val);
			j2++;
		}
		else  {
			str1 = str1.substr(++j2);
			j2=0, j1++;
		}
	} while (str1[j2]);

//	debugPrintVector (p, "Input", nV);
}


int main(){
	// get input
	std::string mystring, tempstring;
	getline(std::cin, mystring);
	std::stringstream stream(mystring);

	// arrays for the cities, cost of building and destroy the roads
	std::vector<int> country, cbuild, cdestroy;
	std::vector<int> *p;

	std::vector<int> bcosts;	// store build costs: least sum of  (n-1)SCC
	std::vector<int> dcosts;	// store destry costs if road is cyclic

	int nV = 0;		// no of vertices
	int nSCC = 0;		// no of SCC
	int nCyclic = 0;	// no of cyclics or forest

	int bcostMin = INF, dcostMin = INF;  // min costs, set to some high number first
	int i = 0;

	// STEP#1 read input, convert to numbers and store in 3 vectors.
	while (i<3 && getline(stream, tempstring, ' ')){
		// 3 strings: 0 - roads, 1 - build costs ,2 - destroy costs
//std::cout << "DEBUG: tempstring='" << tempstring << "'" << std::endl;
		switch(i) {
			case 0:
				// determine number of graph
				nV = count(tempstring.begin(), tempstring.end(), ',') + 1;

				p = &country;
				break;
			case 1:
				p = &cbuild;
				break;
			case 2:
				p = &cdestroy;
				break;
			default:
				break;
		}

		storeIn (p, tempstring, nV);
		i++;
	}

	// STEP#2 Further process the 3 vectors
	// country: no road = INF
	for (i = 0; i < nV; i++) {
		for (int j = 0; j < nV; j++) {
			if (j == i) continue;
// std::cout << "DEBUG: " <<  nV <<" c=" << country.at(j1*nV+j2) <<" from " << j1 << ", " << j2 << std::endl;
// std::cout << "DEBUG: node to add = "<< j1 << ", " << j2 << std::endl;
			if (country.at(i * nV + j) != 1) {
				country.at(i * nV + j) = INF;
			}
		}

	}

//debugPrintVector (&country, "country", nV);

	// STEP#3 Apply Floyd-Warshall Algorithm to det indirect roads
	// hence, no road to build
	// cbuild: yes road = 0 (country > 1)
	for (i = 0; i < nV; i++) {
		for (int j = 0; j < nV; j++) {
			if ((j == i) && (country.at(i * nV + j) <= 1)) continue;
			for (int k = 0; k < nV; k++) {
				if (country.at(i * nV + j) > (country.at(i * nV + k) + country.at(k * nV + j))) 
					country.at(i * nV + j) = country.at(i * nV + k) + country.at(k * nV + j);
			}
			if (country.at(i * nV + j) < INF) {
				cbuild.at(i * nV + j) = 0;
			}
		}
	}

//debugPrintVector (&cbuild, "build", nV);
	// determine SCC
	for (i = 0, nSCC=1; (i+1) < nV; i++) {
		if (country.at(i * nV + i+1) == INF)
			nSCC++;
//std::cout << "DEBUG: i, nSCC= "<< i << ", " << nSCC << std::endl;
	}

	// push build costs to bcosts
	for (int i = 0; i < nV; i++) {
		for (int j = i+1; j < nV; j++) {
			if (cbuild.at(i * nV + j) > 0)
				bcosts.push_back (cbuild.at(i * nV + j));
		}
	}
	// least of (nSCC -1) of costs
	std::sort(bcosts.begin(), bcosts.end());
	bcostMin = std::accumulate(bcosts.begin(), bcosts.begin()+nSCC-1, 0);




	// STEP#4 check cyclic to destroy
	// store destroy costs if cyclic
	// when c[i,j) == c(i,k) and c(k,j)
	std::vector<int> cyclic;
	bool visited[nV];
	for (i = 0; i < nV; i++) visited[i] = false;

	for (i = 0; i < nV; i++) {
		visited[i] = true;
		for (int j = i+1; j < nV; j++) {
			if (country.at(i * nV + j) != 1) continue;
//std::cout << "DEBUG: i,j,nCyclic=" << i << "," <<j<<","<< nCyclic << std::endl;
			if (isCyclic(&country, i, j, nV, visited)) {
//std::cout << "DEBUG: cyclic size,nCyclic=" << cyclic.size() << "," << nCyclic << std::endl;
				if (cyclic.size() == 0) nCyclic = 1;
				else {
					if ((std::find (cyclic.begin(), cyclic.end(), i) == cyclic.end())
						&& (std::find (cyclic.begin(), cyclic.end(), j) == cyclic.end()))
							nCyclic++;
				}
				if (std::find (cyclic.begin(), cyclic.end(), i) == cyclic.end()) {
					cyclic.push_back(i);
					dcosts.push_back (cdestroy.at(i * nV + j));
				}
				if (std::find (cyclic.begin(), cyclic.end(), j) == cyclic.end())
					cyclic.push_back(j);
//std::cout << "DEBUG: after cyclic size,nCyclic=" << cyclic.size() << "," << nCyclic << std::endl;
			}

			
			/*
			for (int k = 0; k < nV; k++) {
				if ((country.at(i * nV + k) == 1) && (country.at(k * nV + j) == 1)) {
					if (cyclic.size() == 0) nCyclic = 1;
					else {
						std::vector<int>::iterator it;	
						if (std::find (cyclic.begin(), cyclic.end(), i) != cyclic.end())
							cyclic.push_back(i);
						if (std::find (cyclic.begin(), cyclic.end(), j) != cyclic.end())
							cyclic.push_back(j);
						if (std::find (cyclic.begin(), cyclic.end(), k) != cyclic.end())
							cyclic.push_back(k);
					}
					dcosts.push_back (cdestroy.at(i * nV + j));
				}
			}
			*/
		}
	}

	// least of (no of cyclics) of costs
	std::sort(dcosts.begin(), dcosts.end());
	dcostMin = std::accumulate(dcosts.begin(), dcosts.begin() + nCyclic, 0);

//debugPrintVector (&cdestroy, "destroy", nV);

	/*
    for (std::vector<int>::iterator cost = dcosts.begin(); cost != dcosts.end(); ++cost) {
		if (dcostMin > *cost) dcostMin = *cost;
	}
	if (dcostMin == INF) dcostMin = 0;
	*/

//std::cout << "DEBUG: build + destroy = " << bcostMin << " + " << dcostMin << std::endl;
//std::cout << "DEBUG: total costs = "<< bcostMin + dcostMin << std::endl;
	std::cout << bcostMin + dcostMin << std::endl;
		
	return 0;
}

