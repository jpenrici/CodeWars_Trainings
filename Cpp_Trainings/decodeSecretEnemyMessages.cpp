/*
CODEWARS
https://www.codewars.com/kata/52cf02cd825aef67070008fa

"Help the general decode secret enemy messages."
*/

#include <iostream>
#include <map>

struct Decoder {
	static std::string decode (const std::string& p_what) {
		std::string out = "";
		std::map<std::string, char> keyMap;
		std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.? !@#$%^&*()_+-";

		for (int i = 0; i < characters.length(); ++i)
		{
			std::string str = "";
			for (int j = 0; j < p_what.length(); ++j)
				str += characters[i];
			keyMap.insert(std::pair<std::string, char>(Encoder::encode(str), characters[i]));
		}

		for (int i = 0; i < p_what.length(); ++i)
			for (auto& character: keyMap)
				if (character.first[i] == p_what[i]) out += character.second;
		return out;
	}
};

/*
struct Decoder {
	static std::string decode (const std::string& p_what) {  
    std::cout << (Encoder::encode ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")) << "\n" ;
    std::cout << (Encoder::encode ("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")) << "\n" ;  
    std::cout << (Encoder::encode ("!@#$%^&*()_+-")) << "\n" ;
    std::string a, b, c;
    for (const auto& w : std::string("abcdefghijklmnopqrstuvwxyz")) {
	    a += Encoder::encode (std::string(  "") + w)[0];
	    b += Encoder::encode (std::string( "_") + w)[1];
	    c += Encoder::encode (std::string("__") + w)[2];
    }
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";		  
    return p_what;
	}
};
*/
