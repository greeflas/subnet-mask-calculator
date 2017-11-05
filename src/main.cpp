#include <iostream>
#include <string>

/**
	Subnet Mask Calculator.
	@author Vladimir Kuprienko <vldmr.kuprienko@gmail.com>
*/
int main()
{
	const unsigned int SUBNET_MASK_PATTERN = 0xFFFFFFFF;
	const short SUBNET_MASK_LENGHT = 32;

	struct IpOctets
	{
		unsigned char octets[4];

		void to_string()
		{
			std::cout << (int)octets[3] << "."
				<< (int)octets[2] << "."
				<< (int)octets[1] << "."
				<< (int)octets[0] << std::endl;
		}
	};

	union IpOctetsConvertor
	{
		unsigned int decimal;
		IpOctets octets;
	};

	std::cout << "----------------------------------------------------" << std::endl
		<< "\tSubnet Mask Calculator" << std::endl << std::endl
		<< " https://github.com/greeflas/subnet-mask-calculator " << std::endl
		<< "----------------------------------------------------" << std::endl
		<< std::endl;

	while (true)
	{
		std::string str;
		std::cout << "Input 'exit' or 'e' for cancel program." << std::endl;
		std::cout << "Input mask in following formats (255.255.255.255/32 or /32)" << std::endl;
		std::cout << "> ";
		std::cin >> str;

		if (str == "exit" || str == "e")
		{
			std::cout << "\nBye!" << std::endl;
			break;
		}

		int slash_idx = str.find('/');
		if (slash_idx != -1)
		{
			str = str.substr(slash_idx + 1);
			int d_subnet_mask = stoi(str);

			IpOctetsConvertor c;
			c.decimal = SUBNET_MASK_PATTERN << (SUBNET_MASK_LENGHT - d_subnet_mask);
			std::cout << "Network mask is: ";
			c.octets.to_string();
		}
		else
		{
			std::cout << "Input mask in correct format!" << std::endl;
		}

		std::cout << std::endl;
	}

	return 0;
}
