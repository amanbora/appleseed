
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2014 Esteban Tovagliari, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

// appleseed.foundation headers.
#include "foundation/math/rng/serialmersennetwister.h"
#ifdef APPLESEED_USE_SSE
#include "foundation/math/rng/simdmersennetwister.h"
#endif
#include "foundation/utility/benchmark.h"

// Standard headers.
#include <cstddef>

using namespace foundation;

BENCHMARK_SUITE(Foundation_Math_Rng_SerialMersenneTwister)
{
    BENCHMARK_CASE(RandUint32)
    {
        SerialMersenneTwister rng;

        for (size_t i = 0; i < 1753117; ++i)
            rng.rand_uint32();
    }
}

#ifdef APPLESEED_USE_SSE
BENCHMARK_SUITE(Foundation_Math_Rng_SimdRngInt32RandomGen)
{
    BENCHMARK_CASE(RandUint32)
    {
        SimdMersenneTwister rng;

        for (size_t i = 0; i < 1753117; ++i)
            rng.rand_uint32();
    }
}
#endif
