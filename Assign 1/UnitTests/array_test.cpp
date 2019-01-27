#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "array.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(one_d_array_test)
	{
	public:

		TEST_METHOD_INITIALIZE(TestInit)
		{
			freopen("Unit_Test_Log.txt", "a+", stdout);
		}

		TEST_METHOD(array_constructor_test)
		{
			// Arrange
			//cout << "(array_constructor_test)" << endl;
			crt_check_memory check;
			dynamic_array<int> array;

			// Act

			// Assert
			Assert::IsTrue(true);
		}

		TEST_METHOD(array_bad_length_test)
		{
			// Arrange
			//out << "(array_bad_length_test)" << endl;
			crt_check_memory check;
			const auto except_show = [] {dynamic_array<int> array(-15, 0); };

			// Act

			// Assert
			Assert::ExpectException<exception>(except_show);
		}

		TEST_METHOD(array_def_Constructor_Check_Start_index)
		{
			// Arrange
			//cout << "(array_def_Constructor_Check_Start_index)" << endl;
			crt_check_memory check;
			dynamic_array<int> array;

			// Act


			// Assert
			Assert::AreEqual(array.get_start_index(), 0);
		}

		TEST_METHOD(array_neg_length_test)
		{
			// Arrange
			//cout << "(array_neg_length_test)" << endl;
			crt_check_memory check;

			const auto except_show = []
			{
				dynamic_array<int> array(5, 0);
				array.set_length(-15);
			};

			// Act


			// Assert
			Assert::ExpectException<exception>(except_show);

		}
		TEST_METHOD(array_copy_constructor_equal_test)
		{
			// Arrange
			//cout << "(array_copy_Constructor_equal_test)" << endl;
			crt_check_memory check;
			dynamic_array<int> myarray(5, -10);
			for (int i = -10; i < -5; i++)
			{
				myarray[i] = i;
				//cout << myarray[i] << " " ;
			}
			
			try
			{
				dynamic_array<int> myarray2(myarray);
				Assert::IsTrue(myarray.get_length() == myarray2.get_length() && myarray.get_start_index() == myarray2.get_start_index());
				for (int i = -10; i < -5; i++)
				{
					Assert::IsTrue(myarray[i] == myarray2[i]);
					//cout << myarray[i] << " " << myarray2[i] << " ";
				}
			}
			catch (std::bad_alloc bad)
			{
				//cout << "**Exception Thrown - Out of Bounds" << endl;
				throw exception("out of bounds");
			}
		}
		TEST_METHOD(array_assign_operator_equal_test)
		{
			// Arrange
			//cout << "(array_assign_operator_equal_test)" << endl;
			dynamic_array<int> array(5, -10);
			for (int i = -10; i < -5; i++)
			{
				array[i] = i;
			}
			dynamic_array<int> array2{};
			array2 = array;
			Assert::IsTrue(array.get_length() == array2.get_length() && array.get_start_index() == array2.get_start_index());
			for (int i = -10; i < -5; i++)
			{
				Assert::IsTrue(array[i] == array2[i]);
			}

		}
		TEST_METHOD(array_self_to_self_assign_operator)
		{
			// Arrange
			//cout << "(array_self_to_self_assign_operator)" << endl;
			crt_check_memory check;
			dynamic_array<int> myarray(5, -10);
			for (int i = -10; i < -5; i++)
			{
				myarray[i] = i;
			}
			try
			{
				myarray = myarray;
				Assert::IsTrue(myarray.get_length() == myarray.get_length() && myarray.get_start_index() == myarray.get_start_index());
				for (int i = -10; i < -5; i++)
				{
					Assert::IsTrue(myarray[i] == myarray[i]);
				}
			}
			catch (exception e)
			{
				Assert::IsTrue(true);
			}

		}

		TEST_METHOD(array_out_of_bounds_max_negative_index_test)
		{
			// Arrange
			//cout << "(array_out_of_bounds_max_negative_index_test)" << endl;
			crt_check_memory check;

			dynamic_array<int> myarray1(5, -10);
			try
			{
				for (int i = -10; i < -4; i++)
				{
					myarray1[i] = i;
				}
			}
			catch (exception e)
			{
				Assert::IsTrue(true);
			}
		}
			
		TEST_METHOD(array_in_bounds_positive_index_test)
		{
			// Arrange
			//cout << "(array_in_bounds_positive_index_test)" << endl;
			crt_check_memory check;
			dynamic_array<int> myarray1(5, 10);
			try
			{
				for (int i = 10; i < 15; i++)
				{
					myarray1[i] = i;
				}
			}
			catch (exception e)
			{
				Assert::IsTrue(true);
			};
		}
		

		TEST_METHOD(array_string_compairson_test)
		{
			// Arrange
			//cout << "(array_out_of_bounds_max_negative_index_test)" << endl;
			crt_check_memory check;

			auto pass = true;
			string name;
			const char* NAMES[] = { "Kyle", "Brit", "Seth", "Alex", "Josh", "Kian", "Kate", "Terry", "Ann", "Elaine", "Stephanie", "Wanda", "Oscar", "Oliver", "Tobey" };

			dynamic_array<string> s_array(15);

			for (int i = 0; i < 15; i++)
			{
				s_array[i] = NAMES[i];
			}

			for (int i = 0; i < 15 && pass; i++)
			{
				name = s_array[i];
				Assert::AreEqual(s_array[i], name);
			}

		}


		TEST_METHOD(array_out_of_bounds_min_negatic_index_test)
		{
			// Arrange
			//cout << "(array_out_of_bounds_max_negative_index_test)" << endl;
			crt_check_memory check;
			dynamic_array<int> array(5, -10);
			try
			{
				for (int i = -11; i < -5; i++)
				{
					array[i] = i;
				}
			}
			catch (exception e)
			{
				Assert::IsTrue(true);
			}
		}

	};
}
