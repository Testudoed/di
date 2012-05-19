//
// Copyright (c) 2012 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "boost/di/aux_/value_type.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/type_traits/is_same.hpp>

#include "boost/di/named.hpp"
#include "data.hpp"

namespace boost {
namespace di {
namespace aux_ {

struct c
{
    typedef int value_type;
};

BOOST_AUTO_TEST_CASE(basic)
{
    BOOST_CHECK((is_same<int, value_type<int>::type>::value));
    BOOST_CHECK((is_same<int, value_type<shared_ptr<int> >::type>::value));
    BOOST_CHECK((is_same<int, value_type<named<int> >::type>::value));
    BOOST_CHECK((is_same<int, value_type<c>::type>::value));
    BOOST_CHECK((is_same<std::string, value_type<std::string>::type>::value));
}

} // namespace aux_
} // namespace di
} // namespace boost

