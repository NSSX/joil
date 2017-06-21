#include "Converter.hpp"

Converter::Converter(void){
    return;
}

Converter::Converter(std::string chaine) : _chaine(chaine){
    searchType(getChaine());
    return;
}

void Converter::goChar(char val){
    std::cout << "Base Type : " << "CHAR"<< std::endl;
    std::cout << "char: " << "'" << val << "'" << std::endl;
	std::cout << "int: " << val << std::endl;
	std::cout << "float: " << val << ".0f" <<  std::endl;
	std::cout << "double: " << val<< ".0" << std::endl;
}

void Converter::goInt(int val){
    std::cout << "Base Type : " << "INT"<< std::endl;
    if (isprint(static_cast<char>(val)))
    {
        std::cout << "char: "<< "'" << static_cast<char>(val) << "'" << std::endl;
    }
    else
        std::cout << "char: " << "Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(val) << std::endl;
    std::cout << std::setprecision(_chaine.length()) << "float: " << static_cast<float>(val) << ".0f"<< std::endl;
    std::cout << std::setprecision(_chaine.length()) << "double: " << static_cast<double>(val) << ".0"<< std::endl;
    return;
}
void Converter::goFloat(float val, int decimalNumber){
    std::cout << "Base Type : " << "FLOAT"<< std::endl;
    if (isprint(static_cast<char>(val)))
    {
        std::cout << "char: "<< "'" << static_cast<char>(val) << "'" << std::endl;
    }
    else
        std::cout << "char: " << "Non displayable" << std::endl;
        if(val <= INT_MAX)
            std::cout << "int: " << static_cast<int>(val) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        double param, fractpart, intpart;
        param = val;
        fractpart = modf (param , &intpart);
        if(decimalNumber > 0 && fractpart > 0){
            std::cout << std::setprecision(this->_size) <<"float: " << static_cast<float>(val) << "f" << std::endl;
            std::cout << std::setprecision(this->_size) <<"double: " << static_cast<double>(val) << std::endl;
        }
        else{
            std::cout << std::setprecision(this->_size) <<"float: " << static_cast<float>(val) << ".0f" << std::endl;
            std::cout << std::setprecision(this->_size) <<"double: " << static_cast<double>(val)<< ".0" << std::endl;
        }
    return;
}
void Converter::goDouble(double val, int decimalNumber){
    std::cout << "Base Type : " << "DOUBLE"<< std::endl;
    if (isprint(static_cast<char>(val)))
    {
        std::cout << "char: "<< "'" << static_cast<char>(val) << "'" << std::endl;
    }
    else
        std::cout << "char: " << "Non displayable" << std::endl;
        if(val <= INT_MAX)
            std::cout << "int: " << static_cast<int>(val) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        double param, fractpart, intpart;
        param = val;
        fractpart = modf (param , &intpart);
        if(decimalNumber > 0 && fractpart > 0){
            if(val <= FLT_MAX)
                std::cout << std::setprecision(_chaine.length()) <<"float: " << static_cast<float>(val) << "f" << std::endl;
            else
            	std::cout << "float: impossible" << std::endl;
            std::cout << std::setprecision(_chaine.length()) <<"double: " << static_cast<double>(val) << std::endl;
        }
        else{
            if(val <= FLT_MAX)
                std::cout << std::setprecision(_chaine.length()) <<"float: " << static_cast<float>(val) << ".0f" << std::endl;
            else
                std::cout << "float: impossible" << std::endl;
            std::cout << std::setprecision(_chaine.length()) <<"double: " << static_cast<double>(val)<< ".0" << std::endl;
        }
    return;
}

void Converter::searchType(std::string chaine){
    this->_size = chaine.length();

    if(chaine == "+inff" || chaine == "+inf"){
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
            return;
    }else if(chaine == "-inff" || chaine == "-inf"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
            return;
    }else if(chaine == "nanf" || chaine == "nan"){
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
            return;
    }

    if(this->_size == 1 && isdigit(chaine[0])){
        goChar(static_cast<char>(chaine[0]));
        return;
    }

    bool floatType = false;
    int size = chaine.length();
    bool realFloat = false;
    int decimalNumber = 0;
    for(int i = 0; i < size; i++){
        if(!isdigit(chaine[i])){
            if(chaine[i] != '.' && chaine[i] != 'f'){
            std::cout << "char: impossible" << std::endl;
    		std::cout << "int: impossible" << std::endl;
    		std::cout << "float: impossible" << std::endl;
    		std::cout << "double: impossible" << std::endl;
            return;
        }
        }
    }

    for(int i = 0; i < size; i++){
        if(chaine[i] == '.'){
            this->_size--;
            int sizeRestant = size - i;
            for(int b = 0; b < sizeRestant ; b++){
                if(isdigit(chaine[b + i]))
                    decimalNumber++;
            }
            floatType = true;
        }
        else if(chaine[i] == 'f'){
            this->_size--;
            floatType = true;
            realFloat = true;
        }
    }
    if(realFloat == true){
        float myFloat = std::atof(chaine.c_str());
        if(myFloat <= FLT_MAX && myFloat >= FLT_MIN){
            //goFloat
            goFloat(static_cast<float>(myFloat), decimalNumber);
        }
        else{
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }
    else if(floatType == true){
        float myFloat = std::atof(chaine.c_str());
        double myDouble = std::atof(chaine.c_str());
        if(myFloat <= FLT_MAX && myFloat >= FLT_MIN){
            //goFloat
            goFloat(static_cast<float>(myFloat), decimalNumber);
        }
        else if(myDouble <= DBL_MAX && myDouble >= DBL_MIN){
            //go double
            goDouble(static_cast<double>(myDouble), decimalNumber);
        }
        else{
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }else{
        long myInt = std::atol(chaine.c_str());
        double myDouble = std::atof(chaine.c_str());
        if(myInt <= INT_MAX && myInt >= INT_MIN){
            //go int
            goInt(static_cast<int>(myInt));
        }
        else if(myDouble <= DBL_MAX && myDouble >= DBL_MIN){
            //go double
            goDouble(static_cast<double>(myDouble), decimalNumber);
        }else{
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }


}

std::string Converter::getChaine(void){
    return this->_chaine;
}


Converter::Converter( Converter const & src){
    *this = src;
    return;
}

Converter::~Converter(void){
    return;
}

Converter & Converter::operator=(Converter const &rhs){
    (void)rhs;
    return (*this);
}
