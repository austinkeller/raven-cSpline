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
			y.push_back(-5.89868e-005);
			y.push_back(0.233061);
			y.push_back(0.216427);
			y.push_back(0.0486148);
			y.push_back(-0.133157);
			y.push_back(-0.172031);
			y.push_back(-0.0456079);
			y.push_back(0.0906686);
			y.push_back(0.116462);
			y.push_back(0.0557287);
			y.push_back(-0.03875);
			y.push_back(-0.10346);
			y.push_back(-0.0734111);
			y.push_back(0.0298435);
			y.push_back(0.094886);
			y.push_back(0.0588743);
			y.push_back(-0.0171021);
			y.push_back(-0.0630512);
			y.push_back(-0.0601684);
			y.push_back(-0.00994154);

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
				double interpolatedX = interpolator.getY(xx);
				double diff = abs(interpolatedX - y[i]);
				Assert::IsTrue(diff < 1.0);
			}
		}
	};
}