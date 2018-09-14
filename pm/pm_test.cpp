/*
   Copyright 2008 Intel Corporation

   Use, modification and distribution are subject to the Boost Software License,
   Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt).
*/

#include <boost/polygon/polygon.hpp>
#include <cassert>
namespace gtl = boost::polygon;
using namespace boost::polygon::operators;
using namespace std;
int main() {

  //lets declare ourselves a polygon set
  using namespace gtl; //because of operators
  typedef std::vector<polygon_data<int> > PolygonSet;
  typedef rectangle_data<int> Rect;
  PolygonSet ps;

  std::vector<rectangle_data<int>> rectangles;
  rectangles.push_back(Rect(0,0,10,10));
  rectangles.push_back(Rect(5,5,15,15));
  rectangles.push_back(Rect(6,6,12,12));
  PolygonSet pset;
  pset.insert(Rect(0,0,10,10));
  cout << " area " << area(pset) << endl;
  //lets put some data in
  ps += rectangle_data<int>(0, 0, 10, 10);

  //now lets do something interesting
  PolygonSet ps2;
  ps2 += rectangle_data<int>(5, 5, 15, 15);
  PolygonSet ps3;
  assign(ps3, ps * ps2); //woah, I just felt the room flex around me
  PolygonSet ps4;
  ps4 += ps + ps2;

  //assert that area of result is equal to sum of areas
  //of input geometry minus the area of overlap between inputs
  assert(area(ps4) == area(ps) + area(ps2) - area(ps3));

  //I don't even see the code anymore, all
  //I see is bounding box...interval...triangle

  //lets try that again in slow motion shall we?
  assert(equivalence((ps + ps2) - (ps * ps2), ps ^ ps2));

  //hmm, subtracting the intersection from the union
  //is equivalent to the xor, all this in one line of code,
  //now we're programming in bullet time
  //(by the way, xor is implemented as one pass, not composition) 

  //just for fun
  rectangle_data<int> rect;
  std::cout << area(ps) << std::endl;
  assert(extents(rect, ps ^ ps2));
  assert(area(rect) == 225);
  assert(area(rect ^ (ps ^ ps2)) == area(rect) - area(ps ^ ps2));
  return 0;
}
