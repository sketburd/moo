// fmt.h: fmt is a function to format strings.
#include <string>




// fmt is a function to simplify string formating.
//
// example)
// 
//     jLO::fmt("I love {}, it's {}", "gelato", "yummy");
//   
//     // returns > "I love gelato, it's yummy"
//
namespace jLO 
{
	// Valid parameter data types are listed below:
	// 
	//     std::string
	//     const char*
	//     int	
	//     long
	//     long long
	//     unsigned
	//     unsigned long
	//     unsigned long long 
	//     float
	//     double
	//     long double
	//



	
	// --- std::string ---
	std::string fmt(const char* fmtStr, std::string val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, std::string val, Args... args);
	// --- const char* ---
	std::string fmt(const char* fmtStr, const char* val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, const char* val, Args... args);
	// --- int ---
	std::string fmt(const char* fmtStr, int val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, int val, Args... args);
	// --- long ---
	std::string fmt(const char* fmtStr, long val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, long val, Args... args);
	// --- long long ---
	std::string fmt(const char* fmtStr, long long val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, long long val, Args... args);
	// --- unsigned ---
	std::string fmt(const char* fmtStr, unsigned val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, unsigned val, Args... args);
	// --- unsigned long ---
	std::string fmt(const char* fmtStr, unsigned long val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, unsigned long val, Args... args);
	// --- unsigned long long ---
	std::string fmt(const char* fmtStr, unsigned long long val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, unsigned long long val, Args... args);
	// --- float ---
	std::string fmt(const char* fmtStr, float val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, float val, Args... args);
	// --- double ---
	std::string fmt(const char* fmtStr, double val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, double val, Args... args);
	// --- long double ---
	std::string fmt(const char* fmtStr, long double val);
	template<typename... Args>
	std::string fmt(const char* fmtStr, long double val, Args... args);
	
	
	

	// Based on a picture I found on the Boyer–Moore string-search algorithm wikipedia page...      
	//
	//                            P A N A M A -
	//
	//                            N A M - - - -
	//                
	//                            - N A M - - -
	//
	//                            - - N A M - -
	//
	//                            - - - N A M -
	//
	std::string fmtParse(const char* fmtStr, std::string val);	
};
































// --- std::string ---
std::string jLO::fmt(const char* fmtStr, std::string val)
{
	return fmtParse(fmtStr, val);
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, std::string val, Args... args)
{
	return jLO::fmt(fmtParse(fmtStr, val).c_str(), args...);
}
// --- const char* ---
std::string jLO::fmt(const char* fmtStr, const char* val)
{
	return fmtParse(fmtStr, std::string(val));
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, const char* val, Args... args)
{	
	return jLO::fmt(fmtParse(fmtStr, std::string(val)).c_str(), args...);
}
// --- int ---
std::string jLO::fmt(const char* fmtStr, int val)
{
	return fmtParse(fmtStr, std::to_string(val));
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, int val, Args... args)
{	
	return jLO::fmt(fmtParse(fmtStr, std::to_string(val)).c_str(), args...);
}
// --- long ---
std::string jLO::fmt(const char* fmtStr, long val)
{
	return fmtParse(fmtStr, std::to_string(val));
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, long val, Args... args)
{	
	return jLO::fmt(fmtParse(fmtStr, std::to_string(val)).c_str(), args...);
}
// --- long long ---
std::string jLO::fmt(const char* fmtStr, long long val)
{
	return fmtParse(fmtStr, std::to_string(val));
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, long long val, Args... args)
{	
	return jLO::fmt(fmtParse(fmtStr, std::to_string(val)).c_str(), args...);
}
// --- unsigned ---
std::string jLO::fmt(const char* fmtStr, unsigned val)
{
	return fmtParse(fmtStr, std::to_string(val));
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, unsigned val, Args... args)
{	
	return jLO::fmt(fmtParse(fmtStr, std::to_string(val)).c_str(), args...);
}
// --- unsigned long ---
std::string jLO::fmt(const char* fmtStr, unsigned long val)
{
	return fmtParse(fmtStr, std::to_string(val));
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, unsigned long val, Args... args)
{	
	return jLO::fmt(fmtParse(fmtStr, std::to_string(val)).c_str(), args...);
}
// --- unsigned long long ---
std::string jLO::fmt(const char* fmtStr, unsigned long long val)
{
	return fmtParse(fmtStr, std::to_string(val));
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, unsigned long long val, Args... args)
{	
	return jLO::fmt(fmtParse(fmtStr, std::to_string(val)).c_str(), args...);
}
// --- float ---
std::string jLO::fmt(const char* fmtStr, float val)
{
	return fmtParse(fmtStr, std::to_string(val));
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, float val, Args... args)
{	
	return jLO::fmt(fmtParse(fmtStr, std::to_string(val)).c_str(), args...);
}
// --- double ---
std::string jLO::fmt(const char* fmtStr, double val)
{
	return fmtParse(fmtStr, std::to_string(val));
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, double val, Args... args)
{	
	return jLO::fmt(fmtParse(fmtStr, std::to_string(val)).c_str(), args...);
}
// --- long double ---
std::string jLO::fmt(const char* fmtStr, long double val)
{
	return fmtParse(fmtStr, std::to_string(val));
}
template<typename... Args>
std::string jLO::fmt(const char* fmtStr, long double val, Args... args)
{	
	return jLO::fmt(fmtParse(fmtStr, std::to_string(val)).c_str(), args...);
}



std::string jLO::fmtParse(const char* fmtStr, std::string val)
{
	std::string retStr("");
	
	for (int index = 0; fmtStr[index + 1] != '\0' ; ++index)
	{
		if (fmtStr[index] == '{' && fmtStr[index + 1] == '}')
		{
			retStr += val;
			
			// just trying to be safe
			if (fmtStr[index + 2] != '\0')
			{			
				retStr += &(fmtStr[index + 2]);
			}

			return retStr;
		}
		
		retStr += fmtStr[index];
	}
	
	return retStr;
}




