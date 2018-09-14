#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<iterator>
#include<sstream>

using namespace std;
#define INF 1000*1000*1000
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
class Wireless {
  public:

    pair<int, int> parseRoam(string roamNode, int &dir) {
      istringstream iss(roamNode);
      string str;
      iss >> str;
      if ( str == "UP" ) { dir = 1; }
      if ( str == "DOWN" ) { dir = 2; }
      if ( str == "LEFT" ) { dir = 3; }
      if ( str == "RIGHT" ) { dir = 4; }
      int x, y;
      iss >> x;
      iss >> y;
      return make_pair(x,y);
    }

    pair<int, int> parseStat(string statNode) {
      istringstream iss(statNode);
      int x, y;
      iss >> x;
      iss >> y;
      return make_pair(x,y);
    }

    int dist2d(pair<int, int> s, pair<int, int> t) {
      int sx, sy, tx, ty;
      sx = s.first;
      sy = s.second;
      tx = t.first;
      ty = t.second;
      return (int) (sqrt( pow((sx-tx),2) + pow((sy-ty), 2) ));
    }

    int findClosest(pair<int, int> coord_2d, vector<pair<int, int> > &nodes, int range) {
        int minVal = INF;
        int minIndex = -1;
        for(int i = 0; i < nodes.size(); i++) {
          int dist = dist2d(coord_2d, nodes[i]);
          if ( dist <= range ) {
            if ( minVal > dist ) {
              minVal = dist;
              minIndex = i;
            }
          }
        }
        return minIndex;
    }

    //floyd-warshall's algorithm for all-pairs shortest path!
    void findAllPaths(vector< vector<int> > &dist, vector<vector<int> > &g) {

        for(int i = 0; i < g.size(); i++) {
        
          for(int j = 0; j < g.size(); j++) {
      
            dist[i][j] = g[i][j];
          
          }
        
        }

        int N= g.size();
        for( int k = 0; k < N; k++) {

          for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if ( dist[i][k] + dist[k][j] < dist[i][j] ) {
                  dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
          }
        }
    }

    void createStatGraph(vector< vector<int> > &g, vector<pair<int, int> > snodes, int range) {
      int N = snodes.size();
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
          if ( i == j ) { 
            g[i][j] = 0;
            continue; 
          }
          int distance = dist2d(snodes[i], snodes[j]);
          if ( distance <= range ) {
            g[i][j] = distance;
          } else {
            g[i][j] = INF;
          }
        }
      }
    }

    int bestRoute(int range, vector<string> roamNodes, vector<string> statNodes) {

      vector<pair<int, int> > snodes(statNodes.size());
      vector<pair<int, int> > rnodes(roamNodes.size());
      vector<int> direction(rnodes.size(), -1);
      vector<vector<int> > G(statNodes.size(), vector<int>(statNodes.size()));
      vector<vector<int> > D(statNodes.size(), vector<int>(statNodes.size()));
      for(int i = 0; i < roamNodes.size(); i++) {
        int d;
        rnodes.push_back(parseRoam(roamNodes[i], d));
        direction.push_back(d);
      }
      for(int i = 0; i < statNodes.size(); i++) {
        snodes.push_back(parseStat(statNodes[i]));
      }
      createStatGraph(G, snodes, range);
      findAllPaths(D, G);
    }
};
