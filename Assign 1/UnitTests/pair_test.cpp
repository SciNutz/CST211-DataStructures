#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "pair.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(pair_test)
	{
	public:

		static pair<int, int> get_pair()
		{
			return pair<int, int>(1, 1);
		}


		TEST_METHOD(pair_copy_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			const pair<int, int> pair1(5, 5);
					   
			// Act
			auto pair2 = pair<int, int>(pair1);


			// Assert
			Assert::AreEqual(pair1.get_first(), pair2.get_first());
			Assert::AreEqual(pair1.get_second(), pair2.get_second());

		}

		TEST_METHOD(pair_move_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			

			// Act
			auto pair2 = std::move(get_pair());


			// Assert
			Assert::AreEqual(1, pair2.get_first());
			Assert::AreEqual(1, pair2.get_second());

		}

		TEST_METHOD(pair_equlity_operator_test)
		{
			// Arrange
			crt_check_memory check;
			const pair<int, int> pair1(5, 5);
			const pair<int, int> pair2(5, 5);


			// Act
			const auto result = pair1 == pair2;


			// Assert
			Assert::IsTrue(result);


		}

		TEST_METHOD(pair_assignment_operator_test)
		{
			// Arrange
			crt_check_memory check;
			pair<int, int> pair1(5, 10);


			// Act
			pair<int, int> pair2(9, 10);
			pair2 = pair1; //shallow copy


			// Assert
			Assert::IsTrue(pair1.get_first() == pair2.get_first() && pair1.get_second() == pair1.get_second());
			
		}

		TEST_METHOD(pair_assignment_operator_teststrings_test)
		{
			// Arrange
			crt_check_memory check;
			pair<std::string, std::string> pair1("Wabbit", "Season");


			// Act
			pair<std::string, std::string> pair2("yes", "no");

			pair2 = pair1; //shallow copy


			// Assert
			Assert::IsTrue(pair1.get_first() == pair2.get_first() && pair1.get_second() == pair1.get_second());

		}

		TEST_METHOD(pair_bool_operator_test)
		{
			// Arrange
			crt_check_memory check;
			pair <std::string, std::string> pair1("Wabbit", "Season");


			// Act
			pair <std::string, std::string> pair2("Wabbit", "Season");


			// Assert
			Assert::IsTrue(pair1 == pair2);
		}

		TEST_METHOD(pair_copy_contructor_string_int_test)
		{
			// Arrange
			crt_check_memory check;
			pair <std::string, int> pair1("Wabbit", 5);


			// Act
			pair<std::string, int> pair2(pair1);


			// Assert
			Assert::IsTrue(pair1.get_first() == pair2.get_first() && pair1.get_second() == pair1.get_second());

		}

		TEST_METHOD(pair_copy_contructor_string_string_test)
		{
			// Arrange
			crt_check_memory check;
			pair <std::string, std::string> pair1("Wabbit", "Season");


			// Act
			pair <std::string, std::string> pair2(pair1);


			// Assert
			Assert::IsTrue(pair1.get_first() == pair2.get_first() && pair1.get_second() == pair1.get_second());

		}

		TEST_METHOD(pair_get_first_test)
		{
			// Arrange
			crt_check_memory check;
			pair <std::string, std::string> pair1("Wabbit", "Season");


			// Act
			std::string test = "Wabbit";


			// Assert
			Assert::AreEqual(pair1.get_first(), test);
		}

		TEST_METHOD(pair_get_second_test)
		{
			// Arrange
			crt_check_memory check;
			pair <std::string, std::string> pair1("Wabbit", "Season");


			// Act
			std::string test = "Season";


			// Assert
			Assert::AreEqual(pair1.get_second(), test);
		}
		TEST_METHOD(pair_set_first_test)
		{
			// Arrange
			crt_check_memory check;
			pair <std::string, std::string> pair1("Wabbit", "Season");


			// Act
			std::string test = "Duck";
			pair1.set_first("Duck");


			// Assert
			Assert::AreEqual(pair1.get_first(), test);
		}

		TEST_METHOD(pair_set_second_test)
		{
			// Arrange
			crt_check_memory check;
			pair <std::string, std::string> pair1("Wabbit", "Season");


			// Act
			std::string test = "Soup";
			pair1.set_second("Soup");

			// Assert
			Assert::AreEqual(pair1.get_second(), test);
		}

	};
}
