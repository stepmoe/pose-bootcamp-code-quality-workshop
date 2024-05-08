#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "address_book.hpp"

TEST_CASE("entries can be added and removed") {
	address_book ab;
	CHECK_FALSE(ab.has_entry("Jane Doe"));
	ab.add_entry("Jane Doe");
	CHECK(ab.has_entry("Jane Doe"));
	ab.remove_entry("Jane Doe");
	CHECK_FALSE(ab.has_entry("Jane Doe"));
}

TEST_CASE("Add entry with valid inputs"){
	address_book ab;
	std::string name = "Test Name";
	uint64_t number = 1234567890;
	unsigned int month = 12;
    unsigned int day = 25;
	ab.add_entry(name);
	ab.set_birthday(name, std::chrono::month_day{std::chrono::month{month}, std::chrono::day{day}});
	ab.set_phone_number(name, number);
	CHECK(ab.has_entry(name));
}

TEST_CASE("Check entry name"){
	address_book ab;
	std::string name = "Test Name";
	ab.remove_entry(name);
	CHECK(ab.list_entries(name));
}

TEST_CASE("Add entry length"){
	address_book ab;
	std::string name = "Testcikowerjdlsjdfoisdlkfmsdlöfjoisdzfpsdojfösdjföpsdjfoisdzufosjdljkjlkcjlkjlijlsdijfjlsdjflsdjf";
	ab.add_entry(name);
	CHECK(ab.has_entry(name));
}