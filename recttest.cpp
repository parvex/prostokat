#include <boost/test/auto_unit_test.hpp>

#include "point.h"
#include "rectangle.h"
using namespace std;

BOOST_AUTO_TEST_SUITE(recttest)

BOOST_AUTO_TEST_CASE( rectsum )
{
	//checking operator +
	Rect test1 = { {6,8}, {10,6} };
	Rect test2 = { {8,5}, {12,9} };
	Rect test3 = test1 + test2;
	Rect correct = { {6,9}, {12,5 } };

	BOOST_CHECK(test3 == correct);


	test1 = { { 12,13 },{ 15,17 } };
	test2 = { { 13,14 },{ 14,16 } };
	test3 = test1 + test2;
	correct = { {12,17}, {15,13} };

	BOOST_CHECK(test3 == correct);


	test1 = { { 1,9 },{ 2,6 } };
	test2 = { { 2,9 },{ 3,6 } };
	test3 = test1 + test2;
	correct = { {1,9}, {3,6} };

	BOOST_CHECK(test3 == correct);

	test1 = { { 2,1 },{ 3,2 } };
	test2 = { { 3,3 },{ 4,2 } };
	test3 = test1 + test2;
	correct = { { 2,3 },{ 4,1 } };

	BOOST_CHECK(test3 == correct);
	
	//summing three rectangles	

	test1 = { {6,8}, {10,6} };
	test2 = { {8,5}, {12,9} };
	test3 = { {9,7}, {10 ,11}};
	correct = { {6,5} , {12,11}};
	test3 = test1 + test2 + test3;
	BOOST_CHECK(test3 == correct);


	test1 = { {1,9}, {2,6} };
	test2 = { {2,9}, {3,6} };
	test3 = { {4,11}, {6,14}};
	correct = { {6,14} , {1,6}};
	test3 = test1 + test2 + test3;
	BOOST_CHECK(test3 == correct);
}

////////////////////
BOOST_AUTO_TEST_CASE(rectsub)
{
	//checking operator -
	Rect test1 = { { 6,8 },{ 10,6 } };
	Rect test2 = { { 8,5 },{ 12,9 } };
	Rect test3 = test1 - test2;
	Rect correct = { { 8,6 },{ 10,8 } }; //

	BOOST_CHECK(test3 == correct);

	test1 = { { 6,8 },{ 10,6 } };
	test2 = { { 8,5 },{ 12,9 } };
	test3 = test2 - test1;
	correct = { { 8,6 },{ 10,8 } }; //

	BOOST_CHECK(test3 == correct);


	test1 = { { 12,13 },{ 15,17 } };
	test2 = { { 13,14 },{ 14,16 } };
	test3 = test1 - test2;
	correct = { { 13,14 },{ 14,16} };

	BOOST_CHECK(test3 == correct);


	test1 = { { 1,9 },{ 2,6 } };
	test2 = { { 2,9 },{ 3,6 } };
	test3 = test1 - test2;
	correct = { { 0,0 },{ 0,0 } };

	BOOST_CHECK(test3 == correct);

	test1 = { { 2,1 },{ 3,2 } };
	test2 = { { 3,3 },{ 4,2 } };
	test3 = test1 - test2;
	correct = { { 0,0 },{ 0,0 } };

	BOOST_CHECK(test3 == correct);


}
//////////////

BOOST_AUTO_TEST_CASE(rectsumto)
{
	//checking operator +=
	Rect test1 = { { 6,8 },{ 10,6 } };
	Rect test2 = { { 8,5 },{ 12,9 } };
	test1 += test2;
	Rect correct = { { 6,9 },{ 12,5 } };

	BOOST_CHECK(test1 == correct);


	test1 = { { 12,13 },{ 15,17 } };
	test2 = { { 13,14 },{ 14,16 } };
	test1 += test2;
	correct = { { 12,17 },{ 15,13 } };

	BOOST_CHECK(test1 == correct);


	test1 = { { 1,9 },{ 2,6 } };
	test2 = { { 2,9 },{ 3,6 } };
	test1 += test2;
	correct = { { 1,9 },{ 3,6 } };

	BOOST_CHECK(test1 == correct);

	test1 = { { 2,1 },{ 3,2 } };
	test2 = { { 3,3 },{ 4,2 } };
	test1 += test2;
	correct = { { 2,3 },{ 4,1 } };

	BOOST_CHECK(test1 == correct);



}
///////////////////
BOOST_AUTO_TEST_CASE(rectsubto)
{
	//checking operator -=
	Rect test1 = { { 6,8 },{ 10,6 } };
	Rect test2 = { { 8,5 },{ 12,9 } };
	test1 -= test2;
	Rect correct = { { 8,6 },{ 10,8 } }; //

	BOOST_CHECK(test1 == correct);

	test1 = { { 6,8 },{ 10,6 } };
	test2 = { { 8,5 },{ 12,9 } };
	test1 -= test2;
	correct = { { 8,6 },{ 10,8 } }; //

	BOOST_CHECK(test1 == correct);


	test1 = { { 12,13 },{ 15,17 } };
	test2 = { { 13,14 },{ 14,16 } };
	test1 -= test2;
	correct = { { 13,14 },{ 14,16 } };

	BOOST_CHECK(test1 == correct);


	test1 = { { 1,9 },{ 2,6 } };
	test2 = { { 2,9 },{ 3,6 } };
	test1 -= test2;
	correct = { { 0,0 },{ 0,0 } };

	BOOST_CHECK(test1 == correct);

	test1 = { { 2,1 },{ 3,2 } };
	test2 = { { 3,3 },{ 4,2 } };
	test1 -= test2;
	correct = { { 0,0 },{ 0,0 } };

	BOOST_CHECK(test1 == correct);


}

///////////////////
BOOST_AUTO_TEST_CASE(rectcrosses)
{
	//checking function crosses
	Rect test1 = { { 6,8 },{ 10,6 } };
	Rect test2 = { { 8,5 },{ 12,9 } };
	Rect correct;

	BOOST_CHECK(test1.crosses(test2));
	BOOST_CHECK(test2.crosses(test1));

	test1 = { { 6,8 },{ 7,120 } };
	test2 = { { 8,5 },{ 15,120 } };

	BOOST_CHECK(!test1.crosses(test2)); //not crossing


	test1 = { { 12,13 },{ 15,17 } };
	test2 = { { 13,14 },{ 14,16 } };
	BOOST_CHECK(test1.crosses(test2));



	test1 = { { 1,9 },{ 2,6 } };
	test2 = { { 2,9 },{ 3,6 } };

	BOOST_CHECK(!test1.crosses(test2)); //not crossing - mutual side

	test1 = { { 2,1 },{ 3,2 } };
	test2 = { { 3,3 },{ 4,2 } };


	BOOST_CHECK(!test2.crosses(test1)); //not crossing - mutual point


}

////

BOOST_AUTO_TEST_CASE(rectencloses)
{
	//checking operator -
	Rect test1 = { { 6,8 },{ 10,6 } };
	Rect test2 = { { 8,5 },{ 12,9 } };
	Rect correct;
	//not enclosing
	BOOST_CHECK(!test1.encloses(test2));
	BOOST_CHECK(!test2.encloses(test1));

	test1 = { { 6,8 },{ 7,120 } };
	test2 = { { 8,5 },{ 15,120 } };

	BOOST_CHECK(!test1.encloses(test2));

	//one enclosing second
	test1 = { { 12,13 },{ 15,17 } };
	test2 = { { 13,14 },{ 14,16 } };
	BOOST_CHECK(test1.encloses(test2));
	BOOST_CHECK(!test2.encloses(test1));


	test1 = { { 4,11 },{ 6,14 } };
	test2 = { { 4,17 },{ 6,11 } };
	BOOST_CHECK(!test1.encloses(test2));
	BOOST_CHECK(test2.encloses(test1));



	test1 = { { 1,9 },{ 2,6 } };
	test2 = { { 1,9 },{ 2,6 } };

	BOOST_CHECK(test1.encloses(test2)); //same rectangles
	BOOST_CHECK(test2.encloses(test1));


	test1 = { { -20,-20 },{20 ,230 } };
	test2 = { { 3,3 },{ 4,2 } };


	BOOST_CHECK(test1.encloses(test2));
	BOOST_CHECK(!test2.encloses(test1));

}

///
BOOST_AUTO_TEST_CASE(recteenclpnt)
{
	//checking function encloses for points


	//points being inside of the rectangle
	Rect test1 = { { 6,8 },{ 10,6 } };
	Point test2 = { 9,7 };

	BOOST_CHECK(test1.encloses(test2));


	test1 = { { 6,8 },{ 20,120 } };
	test2 = { 8,34 };

	BOOST_CHECK(test1.encloses(test2));


	test1 = { { 12,13 },{ 15,17 } };
	test2 = {  13,14};
	BOOST_CHECK(test1.encloses(test2));



	//on the verge

	test1 = { { 1,9 },{ 2,6 } };
	test2 = { 2,6 };

	BOOST_CHECK(!test1.encloses(test2));



	test1 = { { -20,-20 },{ 20 ,230 } };
	test2 = { -20,-20 };


	BOOST_CHECK(!test1.encloses(test2));

	//not inside

	test1 = { { -20,-20 },{ 20 ,230 } };
	test2 = { -60,-200 };

	BOOST_CHECK(!test1.encloses(test2));


	test1 = { { 1,9 },{ 2,6 } };
	test2 = { 0,6 };

	BOOST_CHECK(!test1.encloses(test2));

}

BOOST_AUTO_TEST_SUITE_END()
