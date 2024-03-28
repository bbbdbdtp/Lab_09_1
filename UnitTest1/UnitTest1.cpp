#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_09_1/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(TestCalculateAmount)
		{
			const int N = 4;
			Student students[N];

			students[0].physics_grade = 4;
			students[0].math_grade = 5;
			students[1].physics_grade = 5;
			students[1].math_grade = 4;
			students[2].physics_grade = 5;
			students[2].math_grade = 3;
			students[3].physics_grade = 3;
			students[3].math_grade = 5;

			Assert::AreEqual(2, CalculateAmount(students, N));
		}
	};
}