// format.h: light "std::format / fmt" substitute.
#pragma once
#include <string>




// jlo::format is a function to simplify string formating.
//
// Args:
// - formatString (const char*) : The string model, contains "{}" to show where to insert
//                                arguments. 
// - args (Args...)             : The arguments to insert into formatString. They replace the "{}" 
//                                in the string model.
// 
//                                Valid arguments include:
// 
//                                    std::string
//                                    const char*
//                                    int	
//                                    long
//                                    long long
//                                    unsigned
//                                    unsigned long
//                                    unsigned long long 
//                                    float
//                                    double
//                                    long double
//                          
//
// Returns:
// - std::string: The string model with the inserted arguments.
//
// Examples:
// 
//     jlo::format("{} bars for sale! ${}", "Chocolate", 1);
//     - returns: "Chocolate bars for sale! $1"
//


namespace jlo
{


	extern std::string format(const char* formatString, std::string value); 
	template<typename... Args>
	extern std::string format(const char* formatString, std::string value, Args... args);




	extern std::string format(const char* formatString, const char* value); 
	template<typename... Args>
	extern std::string format(const char* formatString, const char* value, Args... args);	


	
	
	extern std::string format(const char* formatString, int value);
	template<typename... Args>
	extern std::string format(const char* formatString, int value, Args... args);


	
	
	extern std::string format(const char* formatString, long value); 
	template<typename... Args>
	extern std::string format(const char* formatString, long value, Args... args);
	
	
	
	
	extern std::string format(const char* formatString, long long value);
	template<typename... Args>
	extern std::string format(const char* formatString, long long value, Args... args);
	
	
	
	
	extern std::string format(const char* formatString, unsigned value);
	template<typename... Args>
	extern std::string format(const char* formatString, unsigned value, Args... args);
	
	
	
	
	extern std::string format(const char* formatString, unsigned long value);
	template<typename... Args>
	extern std::string format(const char* formatString, unsigned long value, Args... args);
	
	
	

	extern std::string format(const char* formatString, unsigned long long value);
	template<typename... Args>
	extern std::string format(const char* formatString, unsigned long long value, Args... args);
	
	
	
	
	extern std::string format(const char* formatString, float value); 
	template<typename... Args>
	extern std::string format(const char* formatString, float value, Args... args);
	
	
	
	
	extern std::string format(const char* formatString, double value);
	template<typename... Args>
	extern std::string format(const char* formatString, double value, Args... args);
	
	
	
	
	extern std::string format(const char* formatString, long double value);
	template<typename... Args>
	extern std::string format(const char* formatString, long double value, Args... args);
	
	
	


	extern std::string formatParse(const char* formatString, std::string value);	
	
	
};




/* Unit Tests:

std::string a = "a";
const char* b = "b";
int c = 0;
long d = 1;
long long e = 2;
unsigned f = 3;
unsigned long g = 4;
unsigned long long h = 5;
float i = 6;
double j = 7;
long double k = 8;
	
	
std::cout << jlo::format("a:{}\nb:{}\n0:{}\n1:{}\n2:{}\n3:{}\n4:{}\n5:{}\n6.000000:{}\n7.000000:{}\n8.000000:{}\n", a, b, c, d, e, f, g, h, i, j, k);

// Expected Output:
// a:a
// b:b
// 0:0
// 1:1
// 2:2
// 3:3
// 4:4
// 5:5
// 6.000000:6.000000
// 7.000000:7.000000
// 8.000000:8.000000

*/

