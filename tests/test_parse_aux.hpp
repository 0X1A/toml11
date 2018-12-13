#include <iostream>
#include <iomanip>
#include <algorithm>
#include <toml/region.hpp>
#include <toml/result.hpp>

// some of the parsers returns not only a value but also a region.
#define TOML11_TEST_PARSE_EQUAL(psr, tkn, expct)                               \
do {                                                                           \
    const std::string token(tkn);                                              \
    toml::detail::location<std::string> loc("test", token);                    \
    const auto result = psr(loc);                                              \
    BOOST_CHECK(result.is_ok());                                               \
    if(result.is_ok()){                                                        \
    BOOST_CHECK(result.unwrap().first == expct);                               \
    } else {                                                                   \
    std::cerr << "parser " << #psr << " failed with input `";                  \
    std::cerr << token << "`.\n";                                              \
    std::cerr << "reason: " << result.unwrap_err() << '\n';                    \
    }                                                                          \
} while(false);                                                                \
/**/

#define TOML11_TEST_PARSE_EQUAL_VALUE(psr, tkn, expct)                         \
do {                                                                           \
    const std::string token(tkn);                                              \
    toml::detail::location<std::string> loc("test", token);                    \
    const auto result = psr(loc);                                              \
    BOOST_CHECK(result.is_ok());                                               \
    if(result.is_ok()){                                                        \
    BOOST_CHECK(result.unwrap() == expct);                                     \
    } else {                                                                   \
    std::cerr << "parse_value failed with input `";                            \
    std::cerr << token << "`.\n";                                              \
    std::cerr << "reason: " << result.unwrap_err() << '\n';                    \
    }                                                                          \
} while(false);                                                                \
/**/