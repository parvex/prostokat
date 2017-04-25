#include <boost/test/auto_unit_test.hpp>
#include "point.h"
#include "stdafx.h"
#include "rectangle.h"
#include "container.h"
using namespace std;


BOOST_AUTO_TEST_SUITE(rectangle_template_tests)

	BOOST_AUTO_TEST_CASE(rectangle_declaration_and_setting_values)
	{

		Rect<int> test({ 3,5 }, { 4,10 });

		BOOST_CHECK(test.gettopleft().x == 3 && test.gettopleft().y == 10 && test.getbottomright().x == 4 && test.getbottomright().y == 5);
	
		test = { {10,12}, {15,20} };

		BOOST_CHECK(test.gettopleft().x == 10 && test.gettopleft().y == 20 && test.getbottomright().x == 15 && test.getbottomright().y == 12);
	}


	BOOST_AUTO_TEST_CASE(rectangle_template_summing_int1)
	{
		//checking operator +
		Rect<int> test1 = { {6,8}, {10,6} };
		Rect<int> test2 = { {8,5}, {12,9} };
		Rect<int> test3 = test1 + test2;
		Rect<int> correct = { {6,9}, {12,5 } };

		BOOST_CHECK(test3 == correct);
	}

	BOOST_AUTO_TEST_CASE(rectangle_template_summing_int2)
	{
		Rect<int>test1 = { { 12,13 },{ 15,17 } };
		Rect<int> test2 = { { 13,14 },{ 14,16 } };
		Rect<int> test3 = test1 + test2;
		Rect<int> correct = { {12,17}, {15,13} };
		BOOST_CHECK(test3 == correct);
	}

	BOOST_AUTO_TEST_CASE(rectangle_template_summing_int3)
	{



		Rect<int> test1 = { { 1,9 },{ 2,6 } };
		Rect<int> test2 = { { 2,9 },{ 3,6 } };
		Rect<int> test3 = test1 + test2;
		Rect<int> correct = { { 1,9 },{ 3,6 } };

		BOOST_CHECK(test3 == correct);
	}

	BOOST_AUTO_TEST_CASE(rectangle_template_summing_double1)
	{



		Rect<double> test1 = { { 1,9 },{ 2,6 } };
		Rect<double> test2 = { { 2,9 },{ 3,6 } };
		Rect<double> test3 = test1 + test2;
		Rect<double> correct = { {1,9}, {3,6} };

		BOOST_CHECK(test3 == correct);
	}

	BOOST_AUTO_TEST_CASE(rectangle_template_summing_double2)
	{



		Rect<double> test1 = { { 1.2,9.56 },{ 2.666,6.12 } };
		Rect<double> test2 = { { 2.43,9.11 },{ 3.55,6.542 } };
		Rect<double> test3 = test1 + test2;
		Rect<double> correct = { { 1.2,9.56 },{ 3.55,6.12 } };

		BOOST_CHECK(test3 == correct);
	}


	BOOST_AUTO_TEST_CASE(rectangle_template_summing_double3)
	{


		Rect<double> test1 = { { 2.2222222,1.11111 },{ 3.2132,2.33 } };
		Rect<double> test2 = { { 3.1,3.67 },{ 4.43,2.12 } };
		Rect<double> test3 = test1 + test2;
		Rect<double> correct = { { 2.2222222,3.67 },{ 4.43,1.11111 } };

		BOOST_CHECK(test3 == correct);
	}

	BOOST_AUTO_TEST_CASE(rectangle_template_summing_char1)
	{
		//checking operator +
		Rect<char> test1 = { { 6,8 },{ 10,6 } };
		Rect<char> test2 = { { 8,5 },{ 12,9 } };
		Rect<char> test3 = test1 + test2;
		Rect<char> correct = { { 6,9 },{ 12,5 } };

		BOOST_CHECK(test3 == correct);
	}

	BOOST_AUTO_TEST_CASE(rectangle_template_summing_char2)
	{
		Rect<char>test1 = { { 12,13 },{ 15,17 } };
		Rect<char> test2 = { { 13,14 },{ 14,16 } };
		Rect<char> test3 = test1 + test2;
		Rect<char> correct = { { 12,17 },{ 15,13 } };
		BOOST_CHECK(test3 == correct);
	}


	BOOST_AUTO_TEST_CASE(rectangle_template_summing_three_int)
	{
		//summing three rectangles	

		Rect<int> test1 = { { 6,8 },{ 10,6 } };
		Rect<int> test2 = { { 8,5 },{ 12,9 } };
		Rect<int> test3 = { { 9,7 },{ 10 ,11 } };
		Rect<int> correct = { { 6,5 } ,{ 12,11 } };
		test3 = test1 + test2 + test3;
		BOOST_CHECK(test3 == correct);
	}

	BOOST_AUTO_TEST_CASE(rectangle_template_summing_three_double)
	{
		//summing three rectangles	

		Rect<double> test1 = { { 6.11,8 },{ 10,6 } };
		Rect<double> test2 = { { 8,5.23 },{ 12.7,9 } };
		Rect<double> test3 = { { 9,7 },{ 10 ,11.3 } };
		Rect<double> correct = { { 6.11,5.23 } ,{ 12.7,11.3 } };
		test3 = test1 + test2 + test3;
		BOOST_CHECK(test3 == correct);
	}

	BOOST_AUTO_TEST_CASE(rectangle_template_summing_three_char)
	{
		//summing three rectangles	

		Rect<char> test1 = { { 6,8 },{ 10,6 } };
		Rect<char> test2 = { { 8,5 },{ 12,9 } };
		Rect<char> test3 = { { 9,7 },{ 10 ,11 } };
		Rect<char> correct = { { 6,5 } ,{ 12,11 } };
		test3 = test1 + test2 + test3;
		BOOST_CHECK(test3 == correct);
	}


	BOOST_AUTO_TEST_CASE(rectangle_difference_int1)
	{
		//checking operator -
		Rect<int> test1 = { { 6,8 },{ 10,6 } };
		Rect<int> test2 = { { 8,5 },{ 12,9 } };
		Rect<int> test3 = test1 - test2;
		Rect<int> correct = { { 8,6 },{ 10,8 } }; //

		BOOST_CHECK(test3 == correct);
	}
	BOOST_AUTO_TEST_CASE(rectangle_difference_int2)
	{

		Rect<int> test1 = { { 6,8 },{ 10,6 } };
		Rect<int> test2 = { { 8,5 },{ 12,9 } };
		Rect<int> test3 = test2 - test1;
		Rect<int> correct = { { 8,6 },{ 10,8 } }; //

		BOOST_CHECK(test3 == correct);
	}
	BOOST_AUTO_TEST_CASE(rectangle_difference_int3)
	{
		Rect<int> test1 = { { 12,13 },{ 15,17 } };
		Rect<int> test2 = { { 13,14 },{ 14,16 } };
		Rect<int> test3 = test1 - test2;
		Rect<int> correct = { { 13,14 },{ 14,16} };

		BOOST_CHECK(test3 == correct);
	}
	BOOST_AUTO_TEST_CASE(rectangle_difference_int4)
	{
		Rect<int> test1 = { { 1,9 },{ 2,6 } };
		Rect<int> test2 = { { 2,9 },{ 3,6 } };
		Rect<int> test3 = test1 - test2;
		Rect<int> correct = { { 0,0 },{ 0,0 } };

		BOOST_CHECK(test3 == correct);
	}
	BOOST_AUTO_TEST_CASE(rectangle_difference_int5)
	{
		Rect<int> test1 = { { 2,1 },{ 3,2 } };
		Rect<int> test2 = { { 3,3 },{ 4,2 } };
		Rect<int> test3 = test1 - test2;
		Rect<int> correct = { { 0,0 },{ 0,0 } };

		BOOST_CHECK(test3 == correct);


	}

	BOOST_AUTO_TEST_CASE(rectangle_difference_double1)
	{
		//checking operator -
		Rect<double> test1 = { { 6.,8 },{ 10,6 } };
		Rect<double> test2 = { { 8,5 },{ 12,9 } };
		Rect<double> test3 = test1 - test2;
		Rect<double> correct = { { 8,6 },{ 10,8 } }; //

		BOOST_CHECK(test3 == correct);
	}
	BOOST_AUTO_TEST_CASE(rectangle_difference_double2)
	{

		Rect<double> test1 = { { 6,8.16 },{ 10.22,6.33 } };
		Rect<double> test2 = { { 8.1,5 },{ 12,9 } };
		Rect<double> test3 = test2 - test1;
		Rect<double> correct = { { 8.1,6.33 },{ 10.22,8.16 } }; //

		BOOST_CHECK(test3 == correct);
	}
	BOOST_AUTO_TEST_CASE(rectangle_difference_double3)
	{
		Rect<double> test1 = { { 12,13 },{ 15,17 } };
		Rect<double> test2 = { { 13.1,14.2 },{ 14.5,16.2 } };
		Rect<double> test3 = test1 - test2;
		Rect<double> correct = { { 13.1,14.2 },{ 14.5,16.2 } };

		BOOST_CHECK(test3 == correct);
	}


	BOOST_AUTO_TEST_CASE(rectangle_difference_char1)
	{
		//checking operator -
		Rect<char> test1 = { { 6,8 },{ 10,6 } };
		Rect<char> test2 = { { 8,5 },{ 12,9 } };
		Rect<char> test3 = test1 - test2;
		Rect<char> correct = { { 8,6 },{ 10,8 } }; //

		BOOST_CHECK(test3 == correct);
	}
	BOOST_AUTO_TEST_CASE(rectangle_difference_char2)
	{

		Rect<char> test1 = { { 6,8 },{ 10,6 } };
		Rect<char> test2 = { { 8,5 },{ 12,9 } };
		Rect<char> test3 = test2 - test1;
		Rect<char> correct = { { 8,6 },{ 10,8 } }; //

		BOOST_CHECK(test3 == correct);
	}
	BOOST_AUTO_TEST_CASE(rectangle_difference_char3)
	{
		Rect<char> test1 = { { 12,13 },{ 15,17 } };
		Rect<char> test2 = { { 13,14 },{ 14,16 } };
		Rect<char> test3 = test1 - test2;
		Rect<char> correct = { { 13,14 },{ 14,16 } };

		BOOST_CHECK(test3 == correct);
	}
	BOOST_AUTO_TEST_CASE(rectangle_difference_char4)
	{
		Rect<char> test1 = { { 1,9 },{ 2,6 } };
		Rect<char> test2 = { { 2,9 },{ 3,6 } };
		Rect<char> test3 = test1 - test2;
		Rect<char> correct = { { 0,0 },{ 0,0 } };

		BOOST_CHECK(test3 == correct);
	}

	BOOST_AUTO_TEST_CASE(rectangle_crosses_true_int)
	{
		//checking function crosses
		Rect<int> test1 = { { 6,8 },{ 10,6 } };
		Rect<int> test2 = { { 8,5 },{ 12,9 } };


		BOOST_CHECK(test1.crosses(test2));
		BOOST_CHECK(test2.crosses(test1));
	}
	BOOST_AUTO_TEST_CASE(rectangle_crosses_false_int)
	{

		Rect<int> test1 = { { 6,8 },{ 7,120 } };
		Rect<int> test2 = { { 8,5 },{ 15,120 } };

		BOOST_CHECK(!test1.crosses(test2)); //not crossing
	}
	BOOST_AUTO_TEST_CASE(rectangle_crosses_true_int2)
	{
		Rect<int> test1 = { { 12,13 },{ 15,17 } };
		Rect<int> test2 = { { 13,14 },{ 14,16 } };
		BOOST_CHECK(test1.crosses(test2));
	}
	
	BOOST_AUTO_TEST_CASE(rectangle_crosses_false_mutualside_int)
	{
		Rect<int> test1 = { { 1,9 },{ 2,6 } };
		Rect<int> test2 = { { 2,9 },{ 3,6 } };

		BOOST_CHECK(!test1.crosses(test2)); //not crossing - mutual side
	}
	BOOST_AUTO_TEST_CASE(rectangle_crosses_mutualpont_int2)
	{
		Rect<int> test1 = { { 2,1 },{ 3,2 } };
		Rect<int> test2 = { { 3,3 },{ 4,2 } };

		BOOST_CHECK(!test2.crosses(test1)); //not crossing - mutual point

	}

	BOOST_AUTO_TEST_CASE(rectangle_crosses_true_double)
	{
		//checking function crosses
		Rect<double> test1 = { { 6.1,8.1 },{ 10.2,6.3 } };
		Rect<double> test2 = { { 8.4,5.5 },{ 12.1,9.1 } };


		BOOST_CHECK(test1.crosses(test2));
		BOOST_CHECK(test2.crosses(test1));
	}
	BOOST_AUTO_TEST_CASE(rectangle_crosses_false_double)
	{

		Rect<double> test1 = { { 6.1,8.2 },{ 7.2,120 } };
		Rect<double> test2 = { { 8.1,5 },{ 15.3,120 } };

		BOOST_CHECK(!test1.crosses(test2)); //not crossing
	}
	BOOST_AUTO_TEST_CASE(rectangle_crosses_true_double2)
	{
		Rect<double> test1 = { { 12.4,13 },{ 15.5,17 } };
		Rect<double> test2 = { { 13.2,14 },{ 14,16.6 } };
		BOOST_CHECK(test1.crosses(test2));
	}

	BOOST_AUTO_TEST_CASE(rectangle_crosses_false_mutualside_double)
	{
		Rect<double> test1 = { { 1,9.3 },{ 2,6.2 } };
		Rect<double> test2 = { { 2,9.3 },{ 3,6.2 } };

		BOOST_CHECK(!test1.crosses(test2)); //not crossing - mutual side
	}
	BOOST_AUTO_TEST_CASE(rectangle_crosses_mutualpont_double2)
	{
		Rect<double> test1 = { { 2,1 },{ 3.2,2.1 } };
		Rect<double> test2 = { { 3.2,3 },{ 4,2.1 } };

		BOOST_CHECK(!test2.crosses(test1)); //not crossing - mutual point

	}

	BOOST_AUTO_TEST_CASE(rectangle_crosses_true_char)
	{
		//checking function crosses
		Rect<char> test1 = { { 6,8 },{ 10,6 } };
		Rect<char> test2 = { { 8,5 },{ 12,9 } };


		BOOST_CHECK(test1.crosses(test2));
		BOOST_CHECK(test2.crosses(test1));
	}
	BOOST_AUTO_TEST_CASE(rectangle_crosses_false_char)
	{

		Rect<char> test1 = { { 6,8 },{ 7,120 } };
		Rect<char> test2 = { { 8,5 },{ 15,120 } };

		BOOST_CHECK(!test1.crosses(test2)); //not crossing
	}
	BOOST_AUTO_TEST_CASE(rectangle_crosses_true_char2)
	{
		Rect<char> test1 = { { 12,13 },{ 15,17 } };
		Rect<char> test2 = { { 13,14 },{ 14,16 } };
		BOOST_CHECK(test1.crosses(test2));
	}

	BOOST_AUTO_TEST_CASE(rectangle_crosses_false_mutualside_char)
	{
		Rect<char> test1 = { { 1,9 },{ 2,6 } };
		Rect<char> test2 = { { 2,9 },{ 3,6 } };

		BOOST_CHECK(!test1.crosses(test2)); //not crossing - mutual side
	}
	BOOST_AUTO_TEST_CASE(rectangle_crosses_mutualpont_char2)
	{
		Rect<char> test1 = { { 2,1 },{ 3,2 } };
		Rect<char> test2 = { { 3,3 },{ 4,2 } };

		BOOST_CHECK(!test2.crosses(test1)); //not crossing - mutual point

	}

	BOOST_AUTO_TEST_CASE(rectangle_encloses_false_int)
	{
		Rect<int> test1 = { { 6,8 },{ 10,6 } };
		Rect<int> test2 = { { 8,5 },{ 12,9 } };
		//not enclosing

		BOOST_CHECK(!test1.encloses(test2));
		BOOST_CHECK(!test2.encloses(test1));
	}
	BOOST_AUTO_TEST_CASE(rectangle_encloses_fasle_int)
	{
		Rect<int> test1 = { { 6,8 },{ 7,120 } };
		Rect<int> test2 = { { 8,5 },{ 15,120 } };

		BOOST_CHECK(!test1.encloses(test2));
	}
	BOOST_AUTO_TEST_CASE(rectangle_encloses_one_int)
	{
		//one enclosing second
		Rect<int> test1 = { { 12,13 },{ 15,17 } };
		Rect<int> test2 = { { 13,14 },{ 14,16 } };
		BOOST_CHECK(test1.encloses(test2));
		BOOST_CHECK(!test2.encloses(test1));
	}
	BOOST_AUTO_TEST_CASE(rectangle_encloses_one_int2)
	{
		Rect<int> test1 = { { 4,11 },{ 6,14 } };
		Rect<int> test2 = { { 4,17 },{ 6,11 } };
		BOOST_CHECK(!test1.encloses(test2));
		BOOST_CHECK(test2.encloses(test1));
	}
	
	BOOST_AUTO_TEST_CASE(rectangle_encloses_same_int)
	{
		Rect<int> test1 = { { 1,9 },{ 2,6 } };
		Rect<int> test2 = { { 1,9 },{ 2,6 } };

		BOOST_CHECK(test1.encloses(test2)); //same rectangles
		BOOST_CHECK(test2.encloses(test1));
	}
	BOOST_AUTO_TEST_CASE(rectangle_encloses_one_int3)
	{
		Rect<int> test1 = { { -20,-20 },{20 ,230 } };
		Rect<int> test2 = { { 3,3 },{ 4,2 } };


		BOOST_CHECK(test1.encloses(test2));
		BOOST_CHECK(!test2.encloses(test1));
	}




BOOST_AUTO_TEST_CASE(rectangle_encloses_false_double)
{
	Rect<double> test1 = { { 6,8 },{ 10,6 } };
	Rect<double> test2 = { { 8,5 },{ 12,9 } };
	//not enclosing

	BOOST_CHECK(!test1.encloses(test2));
	BOOST_CHECK(!test2.encloses(test1));
}
BOOST_AUTO_TEST_CASE(rectangle_encloses_fasle_double)
{
	Rect<double> test1 = { { 6,8 },{ 7,120 } };
	Rect<double> test2 = { { 8,5 },{ 15,120 } };

	BOOST_CHECK(!test1.encloses(test2));
}
BOOST_AUTO_TEST_CASE(rectangle_encloses_one_double)
{
	//one enclosing second
	Rect<double> test1 = { { 12,13 },{ 15,17 } };
	Rect<double> test2 = { { 13,14 },{ 14,16 } };
	BOOST_CHECK(test1.encloses(test2));
	BOOST_CHECK(!test2.encloses(test1));
}
BOOST_AUTO_TEST_CASE(rectangle_encloses_one_double2)
{
	Rect<double> test1 = { { 4,11 },{ 6,14 } };
	Rect<double> test2 = { { 4,17 },{ 6,11 } };
	BOOST_CHECK(!test1.encloses(test2));
	BOOST_CHECK(test2.encloses(test1));
}

BOOST_AUTO_TEST_CASE(rectangle_encloses_same_double)
{
	Rect<double> test1 = { { 1,9 },{ 2,6 } };
	Rect<double> test2 = { { 1,9 },{ 2,6 } };

	BOOST_CHECK(test1.encloses(test2)); //same rectangles
	BOOST_CHECK(test2.encloses(test1));
}
BOOST_AUTO_TEST_CASE(rectangle_encloses_one_double3)
{
	Rect<double> test1 = { { -20,-20 },{ 20 ,230 } };
	Rect<double> test2 = { { 3,3 },{ 4,2 } };


	BOOST_CHECK(test1.encloses(test2));
	BOOST_CHECK(!test2.encloses(test1));
}


BOOST_AUTO_TEST_CASE(rectangle_encloses_false_char)
{
	Rect<char> test1 = { { 6,8 },{ 10,6 } };
	Rect<char> test2 = { { 8,5 },{ 12,9 } };
	//not enclosing

	BOOST_CHECK(!test1.encloses(test2));
	BOOST_CHECK(!test2.encloses(test1));
}
BOOST_AUTO_TEST_CASE(rectangle_encloses_fasle_char)
{
	Rect<char> test1 = { { 6,8 },{ 7,120 } };
	Rect<char> test2 = { { 8,5 },{ 15,120 } };

	BOOST_CHECK(!test1.encloses(test2));
}
BOOST_AUTO_TEST_CASE(rectangle_encloses_one_char)
{
	//one enclosing second
	Rect<char> test1 = { { 12,13 },{ 15,17 } };
	Rect<char> test2 = { { 13,14 },{ 14,16 } };
	BOOST_CHECK(test1.encloses(test2));
	BOOST_CHECK(!test2.encloses(test1));
}
BOOST_AUTO_TEST_CASE(rectangle_encloses_one_char2)
{
	Rect<char> test1 = { { 4,11 },{ 6,14 } };
	Rect<char> test2 = { { 4,17 },{ 6,11 } };
	BOOST_CHECK(!test1.encloses(test2));
	BOOST_CHECK(test2.encloses(test1));
}

BOOST_AUTO_TEST_CASE(rectangle_encloses_same_char)
{
	Rect<char> test1 = { { 1,9 },{ 2,6 } };
	Rect<char> test2 = { { 1,9 },{ 2,6 } };

	BOOST_CHECK(test1.encloses(test2)); //same rectangles
	BOOST_CHECK(test2.encloses(test1));
}


BOOST_AUTO_TEST_CASE(rectangle_enclosesforpoints_true_int)
{
	//checking function encloses for points


	//points being inside of the rectangle
	Rect<int> test1 = { { 6,8 },{ 10,6 } };
	Point<int> test2 = { 9,7 };

	BOOST_CHECK(test1.encloses(test2));
}

BOOST_AUTO_TEST_CASE(rectangle_enclosesforpoints_true_double)
{
	//checking function encloses for points


	//points being inside of the rectangle
	Rect<double> test1 = { { 6.1,8.2 },{ 10.2,6.3 } };
	Point<double> test2 = { 9.2,7.11 };

	BOOST_CHECK(test1.encloses(test2));
}

BOOST_AUTO_TEST_CASE(rectangle_enclosesforpoints_true_char)
{
	//checking function encloses for points


	//points being inside of the rectangle
	Rect<char> test1 = { { 6,8 },{ 10,6 } };
	Point<char> test2 = { 9,7 };

	BOOST_CHECK(test1.encloses(test2));
}

BOOST_AUTO_TEST_CASE(rectangle_enclosesforpoints_false_int)
{
	Rect<int> test1 = { { 1,9 },{ 2,6 } };
	Point<int> test2 = { 0,6 };

	BOOST_CHECK(!test1.encloses(test2));
}

BOOST_AUTO_TEST_CASE(rectangle_enclosesforpoints_false_double)
{
	Rect<double> test1 = { { 1,9 },{ 2,6 } };
	Point<double> test2 = { 0,6 };

	BOOST_CHECK(!test1.encloses(test2));
}

BOOST_AUTO_TEST_CASE(rectangle_enclosesforpoints_false_char)
{
	Rect<char> test1 = { { 1,9 },{ 2,6 } };
	Point<char> test2 = { 0,6 };

	BOOST_CHECK(!test1.encloses(test2));
}

BOOST_AUTO_TEST_CASE(rectangle_enclosesforpoints_false_verge_int)
{
	Rect<int> test1 = { { 1,9 },{ 2,6 } };
	Point<int> test2 = { 2,6 };

	BOOST_CHECK(!test1.encloses(test2));
}

BOOST_AUTO_TEST_CASE(rectangle_enclosesforpoints_false_verge_double)
{
	Rect<double> test1 = { { 1.1,9.3 },{ 2.4,6 } };
	Point<double> test2 = { 0.2,6 };

	BOOST_CHECK(!test1.encloses(test2));
}

BOOST_AUTO_TEST_CASE(rectangle_enclosesforpoints_false_verge_char)
{
	Rect<char> test1 = { { 1,9 },{ 2,6 } };
	Point<char> test2 = { 0,6 };

	BOOST_CHECK(!test1.encloses(test2));
}



BOOST_AUTO_TEST_SUITE_END()
/////////////////////////////////@@@@@@@@@@@@@@@@@@@@@@@@CONTAINER TESTS


BOOST_AUTO_TEST_SUITE(container_template_tests)


BOOST_AUTO_TEST_CASE(container_operator_plus_equal_for_rect_single)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Container<int> cont;
	cont += rect;
	BOOST_CHECK(cont[0] == rect);


}

BOOST_AUTO_TEST_CASE(container_operator_plus_equal_for_rect_three_mixed_with_add)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Rect<int> rect2 = { { 3,4 },{ 5,7 } };
	Rect<int> rect3 = { { 7,4 },{ 15,27 } };
	Container<int> cont;
	cont += rect;
	cont += rect2;
	cont.add(rect3);

	BOOST_CHECK(cont[0] == rect && cont[1] == rect2 && cont[2] == rect3); //checking if	rect is being saved from the begining

}

BOOST_AUTO_TEST_CASE(container_operator_plus_equal_for_rect_mixed_with_add_overflow)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Rect<int> rect2 = { { 3,4 },{ 5,7 } };
	Rect<int> rect3 = { { 7,4 },{ 15,27 } };
	Container<int> cont(3);
	cont += rect;
	cont += rect2;
	cont.add(rect3);
	cont += rect3;
	cont.add(rect);

	BOOST_CHECK(cont[0] == rect3 && cont[1] == rect3 && cont[2] == rect); //checking if	rect is being saved from the begining

	BOOST_CHECK(cont[10] == rect3); // checking exceeding the actual size of cont

}

BOOST_AUTO_TEST_CASE(container_function_add_six_with_overflow)
{

	Container<int> cont(6);
	Rect<int> r0 = { { 2, 6 },{ 3,8 } }; 
	Rect<int> r1 = { { 6, 10 },{ -2,8 } };
	Rect<int> r2 = { { 2, 2 },{ 3,12 } };
	Rect<int> r3 = { { 4,7 },{ -3,11 } }; 
	Rect<int> r4 = { { 5, 2 },{ 3,122 } };
	Rect<int> r5 = { { 8, 2 },{ 33,124 } }; 


	cont.add(r0); cont.add(r1); cont.add(r2); cont.add(r3); cont.add(r4); cont.add(r5); cont.add(r3); cont.add(r5);

	BOOST_CHECK(cont[0] == r2 && cont[1] == r3 && cont[2] == r4 && cont[3] == r5 && cont[4] == r3 && cont[5] == r5 && cont.size() == 6  && cont.max( ) == 6); 

}

BOOST_AUTO_TEST_CASE(container_function_remove_middle) // also testing temporary object constructor
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Container<int> cont;
	cont += { {5, 4}, { 8,6 }};
	cont += rect;
	cont += { {4, 1}, { 20,8 }};
	cont.remove(1);
	BOOST_CHECK(cont[1] == Rect<int>({ {4, 1}, { 20,8 }}));
}

BOOST_AUTO_TEST_CASE(container_function_remove_three_randomly)
{
	Container<int> cont(6);
	Rect<int> r0 = { {2, 6}, { 3,8 } }; //deleted
	Rect<int> r1 = { {6, 10}, { -2,8 } };
	Rect<int> r2 = { {2, 2}, { 3,12 } };
	Rect<int> r3 =  {{4,7}, { -3,11 } }; //deleted
	Rect<int> r4 = { {5, 2}, { 3,122 } };
	Rect<int> r5 = { {8, 2}, { 33,124 } }; //deleted

	cont.add(r0); cont.add(r1); cont.add(r2); cont.add(r3); cont.add(r4); cont.add(r5);

	BOOST_CHECK(cont.size() == 6);

	cont.remove(0);
	cont.remove(2);
	cont.remove(3);

	//function removes and moves objects to proper place
	BOOST_CHECK(cont[0] == r1 && cont[1] == r2 && cont[2] == r4 && cont[3] == r1 && cont[4] == r2 && cont[5] == r4 && cont.size() == 3); //cont[3],[4],[5] doesn't exist so cont[] returns three first objects

}

BOOST_AUTO_TEST_CASE(container_function_remove_three_randomly_with_overflow)
{
	Container<int> cont(6);
	Rect<int> r0 = { { 2, 6 },{ 3,8 } }; 
	Rect<int> r1 = { { 6, 10 },{ -2,8 } };
	Rect<int> r2 = { { 2, 2 },{ 3,12 } };
	Rect<int> r3 = { { 4,7 },{ -3,11 } }; 
	Rect<int> r4 = { { 5, 2 },{ 3,122 } };
	Rect<int> r5 = { { 8, 2 },{ 33,124 } }; 

	cont.add(r0); cont.add(r1); cont.add(r2); cont.add(r3); cont.add(r4); cont.add(r5); cont.add(r2); cont.add(r5);

	BOOST_CHECK(cont.size() == 6);

	cont.remove(0);
	cont.remove(2);
	cont.remove(3);


	//function removes and moves objects to proper place
	BOOST_CHECK(cont[0] == r3 && cont[1] == r4 && cont[2] == r2 && cont[3] == r3 && cont[4] == r4 && cont[5] == r2 && cont.size() == 3); //cont[3],[4],[5] doesn't exist so cont[] returns three first objects

}


BOOST_AUTO_TEST_CASE(container_function_remove_three_randomly_continuation_checking_add_after)
{
	Container<int> cont(6);
	Rect<int> r0 = { { 2, 6 },{ 3,8 } }; //deleted
	Rect<int> r1 = { { 6, 10 },{ -2,8 } };
	Rect<int> r2 = { { 2, 2 },{ 3,12 } };
	Rect<int> r3 = { { 4,7 },{ -3,11 } }; //deleted
	Rect<int> r4 = { { 5, 2 },{ 3,122 } };
	Rect<int> r5 = { { 8, 2 },{ 33,124 } }; //deleted

	cont.add(r0); cont.add(r1); cont.add(r2); cont.add(r3); cont.add(r4); cont.add(r5);

	BOOST_CHECK(cont.size() == 6);

	cont.remove(0);
	cont.remove(2);
	cont.remove(3);
	//function removes and moves objects to proper place
	BOOST_CHECK(cont[0] == r1 && cont[1] == r2 && cont[2] == r4 && cont[3] == r1 && cont[4] == r2 && cont[5] == r4 && cont.size() == 3); //cont[3],[4],[5] doesn't exist so cont[] returns three first objects

	cont.add(r3).add(r5);

	BOOST_CHECK(cont[0] == r1 && cont[1] == r2 && cont[2] == r4 && cont[3] == r3 && cont[4] == r5 && cont[5] == r1 && cont.size() == 5);
}



BOOST_AUTO_TEST_CASE(container_function_remove_last)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Container<int> cont;
	cont += { {5, 4}, { 8,6 }};
	cont += rect;
	cont += { {4, 1}, { 20,8 }};
	cont.remove(2);
	BOOST_CHECK(cont[2] == Rect<int>({ { 5, 4 },{ 8,6 } }) && cont[1] == rect); //after deleting cont[2] should return first one because [2] doesn't exist and it will return 2 modulo 2 == 0

}


BOOST_AUTO_TEST_CASE(container_function_resize_increasing)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Rect<int> rect2 = { { 3,4 },{ 5,7 } };
	Rect<int> rect3 = { { 7,4 },{ 15,27 } };
	Rect<int> rect4 = { {2,3} , {4,7} };
	Container<int> cont(3);
	cont += rect;   
	cont += rect2;
	cont += rect3;
	cont += rect4;
	cont[0] = rect;
	BOOST_CHECK(cont[0] == rect && cont[1] == rect3 && cont[2] == rect4 && cont[3] == rect && cont.size() == 3 && cont.max() == 3); //checking if overflowing works well, and cont[3] doesn't exist because it was overwritten by saving to cont[0]


	cont.resize(4); //now rec4 should fit 

	cont += rect4;
	BOOST_CHECK(cont[0] == rect && cont[1] == rect3 && cont[2] == rect4 && cont[3] == rect4 && cont.size() == 4 && cont.max() == 4);

}

BOOST_AUTO_TEST_CASE(container_function_resize_increasing_larger)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Rect<int> rect2 = { { 3,4 },{ 5,7 } };
	Rect<int> rect3 = { { 7,4 },{ 15,27 } };
	Rect<int> rect4 = { { 2,3 } ,{ 4,7 } };
	Container<int> cont(3);
	cont += rect;
	cont += rect2;
	cont += rect3;
	cont += rect4;
	cont[0] = rect;
	BOOST_CHECK(cont[0] == rect && cont[1] == rect3 && cont[2] == rect4 && cont[3] == rect && cont.size() == 3 && cont.max() == 3); //checking if overflowing works well, and cont[3] doesn't exist because it was overwritten by saving to cont[0]


	cont.resize(10); 
	

	cont.add(rect4).add(rect3).add(rect).add(rect2);
	BOOST_CHECK(cont[0] == rect && cont[1] == rect3 && cont[2] == rect4 && cont[3] == rect4 && cont.size() == 7 && cont.max() == 10);

	BOOST_CHECK(cont[4] == rect3 && cont[5] == rect && cont[6] == rect2);

}


BOOST_AUTO_TEST_CASE(container_function_resize_increasing_adding_after)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Rect<int> rect2 = { { 3,4 },{ 5,7 } };
	Rect<int> rect3 = { { 7,4 },{ 15,27 } };
	Rect<int> rect4 = { { 2,3 } ,{ 4,7 } };
	Container<int> cont(3);
	cont += rect;
	cont += rect2;
	cont += rect3;
	cont += rect4;
	cont[0] = rect;

	cont.resize(5); 

	cont += rect4;

	cont.add(rect);

	BOOST_CHECK(cont[0] == rect && cont[1] == rect3 && cont[2] == rect4 && cont[3] == rect4 && cont[4] == rect && cont.size() == 5 && cont.max() == 5);
}

BOOST_AUTO_TEST_CASE(container_function_resize_decreasing)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Rect<int> rect2 = { { 3,4 },{ 5,7 } };
	Rect<int> rect3 = { { 7,4 },{ 15,27 } };
	Rect<int> rect4 = { { 2,3 } ,{ 4,7 } };
	Container<int> cont(4);
	cont += rect;
	cont += rect2;
	cont += rect3;
	cont += rect4;

	BOOST_CHECK(cont[0] == rect && cont[1] == rect2 && cont[2] == rect3 && cont[3] == rect4 && cont.size() == 4 && cont.max() == 4);


	cont.resize(2); //now the size should be 2 and cont[2],[3],[4] should be rect and rect2, because rect3 and rect4 were deleted

	BOOST_CHECK(cont[0] == rect && cont[1] == rect2 && cont[2] == rect && cont[3] == rect2  && cont.size() == 2 && cont.max() == 2);

}

BOOST_AUTO_TEST_CASE(container_function_resize_decreasing_larger_overflow)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Rect<int> rect2 = { { 3,4 },{ 5,7 } };
	Rect<int> rect3 = { { 7,4 },{ 15,27 } };
	Rect<int> rect4 = { { 2,3 } ,{ 4,7 } };
	Container<int> cont(7);
	cont += rect;
	cont += rect2;
	cont += rect3;
	cont += rect4;
	cont.add(rect).add(rect2).add(rect3).add(rect4).add(rect2);



	cont.resize(4); //now the size should be 2 and cont[2],[3],[4] should be rect and rect2, because rect3 and rect4 were deleted

	BOOST_CHECK(cont[0] == rect3 && cont[1] == rect4 && cont[2] == rect && cont[3] == rect2  && cont.size() == 4 && cont.max() == 4);

}


BOOST_AUTO_TEST_CASE(container_function_resize_decreasing_overflowing_after)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Rect<int> rect2 = { { 3,4 },{ 5,7 } };
	Rect<int> rect3 = { { 7,4 },{ 15,27 } };
	Rect<int> rect4 = { { 2,3 } ,{ 4,7 } };
	Container<int> cont(4);
	cont += rect;
	cont += rect2;
	cont += rect3;
	cont += rect4;

	BOOST_CHECK(cont[0] == rect && cont[1] == rect2 && cont[2] == rect3 && cont[3] == rect4 && cont.size() == 4 && cont.max() == 4);


	cont.resize(2); //now the size should be 2 and cont[2],[3],[4] should be rect and rect2, because rect3 and rect4 were deleted

	BOOST_CHECK(cont[0] == rect && cont[1] == rect2 && cont[2] == rect && cont[3] == rect2  && cont.size() == 2 && cont.max() == 2);

	cont.add(rect4);


	
	BOOST_CHECK(cont[1] == rect4 && cont[0] == rect2 && cont[1] == rect4 && cont[0] == rect2  && cont.size() == 2 && cont.max() == 2);

}



BOOST_AUTO_TEST_CASE(container_function_border1)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };
	Rect<int> rect2 = { { 3,4 },{ 5,7 } };
	Rect<int> rect3 = { { 7,4 },{ 15,27 } };
	Rect<int> rect4 = { { 2,3 } ,{ 4,7 } };
	Container<int> cont(4);
	cont += rect;
	cont += rect2;
	cont += rect3;
	cont += rect4;

	BOOST_CHECK(cont.border() == Rect<int>({ {2, 27}, {15, 3} }));

}

BOOST_AUTO_TEST_CASE(container_function_border2)
{
	Rect<int> rect = { { -20,9 },{ 4,6 } };
	Rect<int> rect2 = { { 4,4 },{ 6,7 } };
	Rect<int> rect3 = { { 7,4 },{ 15,328 } };
	Rect<int> rect4 = { { 1,-9 } ,{ 3,7 } };
	Container<int> cont(4);
	cont += rect;
	cont += rect2;
	cont += rect3;
	cont += rect4;

	BOOST_CHECK(cont.border() == Rect<int>({ { -20, 328 },{ 15, -9 } }));

}

BOOST_AUTO_TEST_CASE(container_function_border_double)
{
	Rect<double> rect = { { -20.23,9.1 },{ 4.4,6.6 } };
	Rect<double> rect2 = { { 4.6,4 },{ 6,7.1 } };
	Rect<double> rect3 = { { 7,4 },{ 15,328.3 } };
	Rect<double> rect4 = { { 1.5,-9.5 } ,{ 3,7.1 } };
	Container<double> cont(4);
	cont += rect;
	cont += rect2;
	cont += rect3;
	cont += rect4;

	BOOST_CHECK(cont.border() == Rect<double>({ { -20.23, 328.3 },{ 15, -9.5} }));

}

BOOST_AUTO_TEST_CASE(container_function_border_same_int)
{
	Rect<int> rect = { { 3,9 },{ 4,6 } };

	Container<int> cont(4);
	cont += rect;
	cont += rect;
	cont += rect;
	cont += rect;

	BOOST_CHECK(cont.border() == rect);

}


BOOST_AUTO_TEST_SUITE_END()







































































//BOOST_AUTO_TEST_CASE(recteenclpnt)
//{
//	//checking function encloses for points
//	
//	
//	//points being inside of the rectangle
//	Rect test1 = { { 6,8 },{ 10,6 } };
//	Point test2 = { 9,7 };
//	
//	BOOST_CHECK(test1.encloses(test2));
//	
//	
//	test1 = { { 6,8 },{ 20,120 } };
//	test2 = { 8,34 };
//	
//	BOOST_CHECK(test1.encloses(test2));
//	
//	
//	test1 = { { 12,13 },{ 15,17 } };
//	test2 = {  13,14};
//	BOOST_CHECK(test1.encloses(test2));
//	
//	
//	
//	//on the verge
//	
//	test1 = { { 1,9 },{ 2,6 } };
//	test2 = { 2,6 };
//	
//	BOOST_CHECK(!test1.encloses(test2));
//	
//	
//	
//	test1 = { { -20,-20 },{ 20 ,230 } };
//	test2 = { -20,-20 };
//	
//	
//	BOOST_CHECK(!test1.encloses(test2));
//	
//	//not inside
//	
//	test1 = { { -20,-20 },{ 20 ,230 } };
//	test2 = { -60,-200 };
//	
//	BOOST_CHECK(!test1.encloses(test2));
//	
//	
//	test1 = { { 1,9 },{ 2,6 } };
//	test2 = { 0,6 };
//	
//	BOOST_CHECK(!test1.encloses(test2));
//	
//}
//
















//
//BOOST_AUTO_TEST_SUITE(rectangle_tests)
//
//BOOST_AUTO_TEST_CASE( rectsum )
//{
//	//checking operator +
//	Rect test1 = { {6,8}, {10,6} };
//	Rect test2 = { {8,5}, {12,9} };
//	Rect test3 = test1 + test2;
//	Rect correct = { {6,9}, {12,5 } };
//
//	BOOST_CHECK(test3 == correct);
//
//
//	test1 = { { 12,13 },{ 15,17 } };
//	test2 = { { 13,14 },{ 14,16 } };
//	test3 = test1 + test2;
//	correct = { {12,17}, {15,13} };
//
//	BOOST_CHECK(test3 == correct);
//
//
//	test1 = { { 1,9 },{ 2,6 } };
//	test2 = { { 2,9 },{ 3,6 } };
//	test3 = test1 + test2;
//	correct = { {1,9}, {3,6} };
//
//	BOOST_CHECK(test3 == correct);
//
//	test1 = { { 2,1 },{ 3,2 } };
//	test2 = { { 3,3 },{ 4,2 } };
//	test3 = test1 + test2;
//	correct = { { 2,3 },{ 4,1 } };
//
//	BOOST_CHECK(test3 == correct);
//	
//	//summing three rectangles	
//
//	test1 = { {6,8}, {10,6} };
//	test2 = { {8,5}, {12,9} };
//	test3 = { {9,7}, {10 ,11}};
//	correct = { {6,5} , {12,11}};
//	test3 = test1 + test2 + test3;
//	BOOST_CHECK(test3 == correct);
//
//
//	test1 = { {1,9}, {2,6} };
//	test2 = { {2,9}, {3,6} };
//	test3 = { {4,11}, {6,14}};
//	correct = { {6,14} , {1,6}};
//	test3 = test1 + test2 + test3;
//	BOOST_CHECK(test3 == correct);
//}
//
//////////////////////
//BOOST_AUTO_TEST_CASE(rectsub)
//{
//	//checking operator -
//	Rect test1 = { { 6,8 },{ 10,6 } };
//	Rect test2 = { { 8,5 },{ 12,9 } };
//	Rect test3 = test1 - test2;
//	Rect correct = { { 8,6 },{ 10,8 } }; //
//
//	BOOST_CHECK(test3 == correct);
//
//	test1 = { { 6,8 },{ 10,6 } };
//	test2 = { { 8,5 },{ 12,9 } };
//	test3 = test2 - test1;
//	correct = { { 8,6 },{ 10,8 } }; //
//
//	BOOST_CHECK(test3 == correct);
//
//
//	test1 = { { 12,13 },{ 15,17 } };
//	test2 = { { 13,14 },{ 14,16 } };
//	test3 = test1 - test2;
//	correct = { { 13,14 },{ 14,16} };
//
//	BOOST_CHECK(test3 == correct);
//
//
//	test1 = { { 1,9 },{ 2,6 } };
//	test2 = { { 2,9 },{ 3,6 } };
//	test3 = test1 - test2;
//	correct = { { 0,0 },{ 0,0 } };
//
//	BOOST_CHECK(test3 == correct);
//
//	test1 = { { 2,1 },{ 3,2 } };
//	test2 = { { 3,3 },{ 4,2 } };
//	test3 = test1 - test2;
//	correct = { { 0,0 },{ 0,0 } };
//
//	BOOST_CHECK(test3 == correct);
//
//
//}
////////////////
//
//BOOST_AUTO_TEST_CASE(rectsumto)
//{
//	//checking operator +=
//	Rect test1 = { { 6,8 },{ 10,6 } };
//	Rect test2 = { { 8,5 },{ 12,9 } };
//	test1 += test2;
//	Rect correct = { { 6,9 },{ 12,5 } };
//
//	BOOST_CHECK(test1 == correct);
//
//
//	test1 = { { 12,13 },{ 15,17 } };
//	test2 = { { 13,14 },{ 14,16 } };
//	test1 += test2;
//	correct = { { 12,17 },{ 15,13 } };
//
//	BOOST_CHECK(test1 == correct);
//
//
//	test1 = { { 1,9 },{ 2,6 } };
//	test2 = { { 2,9 },{ 3,6 } };
//	test1 += test2;
//	correct = { { 1,9 },{ 3,6 } };
//
//	BOOST_CHECK(test1 == correct);
//
//	test1 = { { 2,1 },{ 3,2 } };
//	test2 = { { 3,3 },{ 4,2 } };
//	test1 += test2;
//	correct = { { 2,3 },{ 4,1 } };
//
//	BOOST_CHECK(test1 == correct);
//
//
//
//}
/////////////////////
//BOOST_AUTO_TEST_CASE(rectsubto)
//{
//	//checking operator -=
//	Rect test1 = { { 6,8 },{ 10,6 } };
//	Rect test2 = { { 8,5 },{ 12,9 } };
//	test1 -= test2;
//	Rect correct = { { 8,6 },{ 10,8 } }; //
//
//	BOOST_CHECK(test1 == correct);
//
//	test1 = { { 6,8 },{ 10,6 } };
//	test2 = { { 8,5 },{ 12,9 } };
//	test1 -= test2;
//	correct = { { 8,6 },{ 10,8 } }; //
//
//	BOOST_CHECK(test1 == correct);
//
//
//	test1 = { { 12,13 },{ 15,17 } };
//	test2 = { { 13,14 },{ 14,16 } };
//	test1 -= test2;
//	correct = { { 13,14 },{ 14,16 } };
//
//	BOOST_CHECK(test1 == correct);
//
//
//	test1 = { { 1,9 },{ 2,6 } };
//	test2 = { { 2,9 },{ 3,6 } };
//	test1 -= test2;
//	correct = { { 0,0 },{ 0,0 } };
//
//	BOOST_CHECK(test1 == correct);
//
//	test1 = { { 2,1 },{ 3,2 } };
//	test2 = { { 3,3 },{ 4,2 } };
//	test1 -= test2;
//	correct = { { 0,0 },{ 0,0 } };
//
//	BOOST_CHECK(test1 == correct);
//
//
//}
//
/////////////////////
//BOOST_AUTO_TEST_CASE(rectcrosses)
//{
//	//checking function crosses
//	Rect test1 = { { 6,8 },{ 10,6 } };
//	Rect test2 = { { 8,5 },{ 12,9 } };
//	Rect correct;
//
//	BOOST_CHECK(test1.crosses(test2));
//	BOOST_CHECK(test2.crosses(test1));
//
//	test1 = { { 6,8 },{ 7,120 } };
//	test2 = { { 8,5 },{ 15,120 } };
//
//	BOOST_CHECK(!test1.crosses(test2)); //not crossing
//
//
//	test1 = { { 12,13 },{ 15,17 } };
//	test2 = { { 13,14 },{ 14,16 } };
//	BOOST_CHECK(test1.crosses(test2));
//
//
//
//	test1 = { { 1,9 },{ 2,6 } };
//	test2 = { { 2,9 },{ 3,6 } };
//
//	BOOST_CHECK(!test1.crosses(test2)); //not crossing - mutual side
//
//	test1 = { { 2,1 },{ 3,2 } };
//	test2 = { { 3,3 },{ 4,2 } };
//
//
//	BOOST_CHECK(!test2.crosses(test1)); //not crossing - mutual point
//
//
//}
//
//////
//
//BOOST_AUTO_TEST_CASE(rectencloses)
//{
//	//checking operator -
//	Rect test1 = { { 6,8 },{ 10,6 } };
//	Rect test2 = { { 8,5 },{ 12,9 } };
//	Rect correct;
//	//not enclosing
//	BOOST_CHECK(!test1.encloses(test2));
//	BOOST_CHECK(!test2.encloses(test1));
//
//	test1 = { { 6,8 },{ 7,120 } };
//	test2 = { { 8,5 },{ 15,120 } };
//
//	BOOST_CHECK(!test1.encloses(test2));
//
//	//one enclosing second
//	test1 = { { 12,13 },{ 15,17 } };
//	test2 = { { 13,14 },{ 14,16 } };
//	BOOST_CHECK(test1.encloses(test2));
//	BOOST_CHECK(!test2.encloses(test1));
//
//
//	test1 = { { 4,11 },{ 6,14 } };
//	test2 = { { 4,17 },{ 6,11 } };
//	BOOST_CHECK(!test1.encloses(test2));
//	BOOST_CHECK(test2.encloses(test1));
//
//
//
//	test1 = { { 1,9 },{ 2,6 } };
//	test2 = { { 1,9 },{ 2,6 } };
//
//	BOOST_CHECK(test1.encloses(test2)); //same rectangles
//	BOOST_CHECK(test2.encloses(test1));
//
//
//	test1 = { { -20,-20 },{20 ,230 } };
//	test2 = { { 3,3 },{ 4,2 } };
//
//
//	BOOST_CHECK(test1.encloses(test2));
//	BOOST_CHECK(!test2.encloses(test1));
//
//}
//
/////
//BOOST_AUTO_TEST_CASE(recteenclpnt)
//{
//	//checking function encloses for points
//
//
//	//points being inside of the rectangle
//	Rect test1 = { { 6,8 },{ 10,6 } };
//	Point test2 = { 9,7 };
//
//	BOOST_CHECK(test1.encloses(test2));
//
//
//	test1 = { { 6,8 },{ 20,120 } };
//	test2 = { 8,34 };
//
//	BOOST_CHECK(test1.encloses(test2));
//
//
//	test1 = { { 12,13 },{ 15,17 } };
//	test2 = {  13,14};
//	BOOST_CHECK(test1.encloses(test2));
//
//
//
//	//on the verge
//
//	test1 = { { 1,9 },{ 2,6 } };
//	test2 = { 2,6 };
//
//	BOOST_CHECK(!test1.encloses(test2));
//
//
//
//	test1 = { { -20,-20 },{ 20 ,230 } };
//	test2 = { -20,-20 };
//
//
//	BOOST_CHECK(!test1.encloses(test2));
//
//	//not inside
//
//	test1 = { { -20,-20 },{ 20 ,230 } };
//	test2 = { -60,-200 };
//
//	BOOST_CHECK(!test1.encloses(test2));
//
//
//	test1 = { { 1,9 },{ 2,6 } };
//	test2 = { 0,6 };
//
//	BOOST_CHECK(!test1.encloses(test2));
//
//}
//
//BOOST_AUTO_TEST_SUITE_END()
