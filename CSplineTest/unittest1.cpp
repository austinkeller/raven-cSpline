#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include "../CSpline/CSpline.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CSplineTest
{		
	using namespace std;

	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(CubicHermiteSplineTest1)
		{
			vector<double> x;
			vector<double> y;
			x.push_back(3.1415);
			x.push_back(3.63753);
			x.push_back(4.13355);
			x.push_back(4.62958);
			x.push_back(5.12561);
			x.push_back(5.62163);
			x.push_back(6.11766);
			x.push_back(6.61368);
			x.push_back(7.10971);
			x.push_back(7.60574);
			x.push_back(8.10176);
			x.push_back(8.59779);
			x.push_back(9.09382);
			x.push_back(9.58984);
			x.push_back(10.0859);
			x.push_back(10.5819);
			x.push_back(11.0779);
			x.push_back(11.5739);
			x.push_back(12.07);
			x.push_back(12.566);
			y.push_back(-0.0000589868465782519);
			y.push_back(0.14463484548733077);
			y.push_back(0.19446333430646837);
			y.push_back(0.071842906721276842);
			y.push_back(-0.12053092959435169);
			y.push_back(-0.17673049248020398);
			y.push_back(-0.050647231032090206);
			y.push_back(0.091041384836209341);
			y.push_back(0.11811218795866396);
			y.push_back(0.056011414090931771);
			y.push_back(-0.039200200662229685);
			y.push_back(-0.10365370318116232);
			y.push_back(-0.073325998546899918);
			y.push_back(0.029887475008922595);
			y.push_back(0.094896084461076571);
			y.push_back(0.058997921877052412);
			y.push_back(-0.01705592142914425);
			y.push_back(-0.063504217774696767);
			y.push_back(-0.060630871127830416);
			y.push_back(-0.0088098615595968918);

			vector<double> xIn;
			vector<double> yIn;
			const double PI = 3.1415;
			const int N = 12;
			double xx = PI;
			double step = 4 * PI / (N - 1);
			for (int i = 0; i < N; ++i, xx += step)
			{
				xIn.push_back(xx);
				yIn.push_back(sin(2 * xx) / xx);
			}

			cSpline interpolator(xIn, yIn);
			const int N_out = 20;
			xx = PI;
			step = (3 * PI) / (N_out - 1);
			for (int i = 0; i < N_out; ++i, xx += step)
			{
				double interpolatedY = interpolator.getY(xx);
				double diff = abs(interpolatedY - y[i]);
				Assert::IsTrue(diff < 1e-5);
			}
		}

		TEST_METHOD(CubicHermiteSplineTest2)
		{
			// Test extrapolation
			vector<double> x;
			vector<double> y;
			x.push_back(0.0635025624);
			x.push_back(0.1808948136);
			x.push_back(0.304432644533);
			y.push_back(0.0);
			y.push_back(13047.732421875);
			y.push_back(0.0);

			cSpline interpolator(x, y);

			double interpolatedY = interpolator.getY(0.006111831467);
			double diff = abs(interpolatedY - -8685.1482789803285);
			Assert::IsTrue(diff < 1e-5);
		}
	};
}