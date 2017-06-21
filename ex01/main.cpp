#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Data.hpp"

void gen_random(char *s, const int len) {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

void		*serialize( void )
{
	char	*serializedData = new char[20];
	int		randomInteger = 1000 + (rand() % static_cast<int>(2000 - 1000 + 1));
	char	chaine1[8];
	char	chaine2[8];

	gen_random(chaine1, 8);
	gen_random(chaine2, 8);
	std::cout << "Chaine 1 : " <<chaine1 << " , Random Integer : " << randomInteger << " , chaine2 : "<<chaine2 <<std::endl;
	for(int i = 0; i < 8; i++)
		serializedData[i] = chaine1[i];
	int	 *serializedDataint = reinterpret_cast<int*>(&serializedData[8]);
	*serializedDataint = randomInteger;
	for(int i = 0; i < 8; i++)
		serializedData[i + 12] = chaine2[i];
	return serializedData;
}


Data		*deserialize( void *raw )
{
	int		nbr = 0;
	int		*serializedInt;
	Data	*data = new Data;

	char	*deserializeString = static_cast<char*>(raw);

    for(int i = 0; i < 8; i++){
        data->s1 += deserializeString[i];
    }

    serializedInt = reinterpret_cast<int*>(&deserializeString[8]);
    nbr = *serializedInt;
    data->n = nbr;

    for(int i = 0; i < 8; i++){
        data->s2 += deserializeString[i + 12];
    }

	return data;
}

int			main(void)
{
	srand(time(NULL));
	void	*serializedData;
	Data	*data;

	serializedData = serialize();
	data = deserialize(serializedData);
    std::cout << "Serialized Data Adress : " << serializedData << std::endl;
    std::cout << "Chaine 1 : " << data->s1 << " , Random Integer : " << data->n << " , chaine2 : "<< data->s2 <<std::endl;

	return 0;
}
