#pragma once
#include <sstream>


#define __OUT_PRECISION__ 16


namespace Utility
{

//Type Def Declarations////////////////////////////////////	

	typedef long int lint_t;
//Type Def Declarations////////////////////////////////////	
	//1a
	lint_t inline POW10(unsigned int zeros)
	{
		lint_t temp = 1;
		for(int i = zeros; i > 0; i--)
		{
			temp*=10;
		}

		return temp;
	} //End of POW10

	//1b
	template <typename R>
	R inline POW10(unsigned int zeros)
	{
		R temp;
		for(int i = zeros; i > 0; i++)
		{
			temp*=10;
		}

		return temp;
	} //End of POW10

	//2
	template <typename T>
	std::string inline POW10_Rep(T num)
	{
		int temp = floor(log10(num));
		std::ostringstream buffer;
		buffer << 10 << "^" << temp;
		return buffer.str();
	}

	//3
	//Function to combine paths, file=false ->end terminated by a slash
	std::string inline Path_Union(std::string Parent, std::string AddString, bool file=true)
	{
		//Read System Information -> Windows mode or linux
	}

	//4
	//Create New Output Terminal and return the path and pid of that terminal.
	std::tuple<std::string, std::unsigned int> Output_Terminal()
	{

	}

	//5a
	//Make System Call
	void MakeSysCall(std::string command, std::string stringkey)
	{
		std::cout <<"Executed System Call: " << stringkey 
				  <<". Returned PID:" << system(command.c_str()) <<std::endl;
	}//Make System Call

	//5b
	//Make System Call
	std::string MakeSysCall_S(std::string command, std::string stringkey)
	{
		std::ostringstream buffer;
		buffer  <<"Executed System Call: " << stringkey 
				<<". Returned PID:" << system(command.c_str()) <<std::endl;
		return buffer.str();

	}//Make System Call


	//6a
	bool SetFile(const std::string &path, const std::string &content)
	{
		std::fstream file(path, ios::out);
		if(file.is_open())
		{
			file << content;
			file.close();
			return true;
		}

		else
			return false;
	}

	//6b
	bool SetFile(const std::string &path, const std::stringstream &content)
	{
		std::fstream file(path, ios::out);
		if(file.is_open())
		{
			file << content.str();
			file.close();
			return true;
		}

		else
			return false;
	}


	//7a
	bool AppFile(const std::string &path, const std::string &content)
	{
		std::fstream file(path, ios::app);
		if(file.is_open())
		{
			file << content;
			file.close();
			return true;
		}

		else
			return false;
	}

	//7b
	bool AppFile(const std::string &path, const std::stringstream &content)
	{
		std::fstream file(path, ios::app);
		if(file.is_open())
		{
			file << content.str();
			file.close();
			return true;
		}

		else
			return false;
	}

	/*//8 ===> Incomplete
	template <typename T>
	std::string Print_Matrix(std::string &nametoken, T arrptr[], std::vector<unsigned int> &dims, )
	{
		int dimensions = dims.size();
		if(dimensions ==0 || dimensions >3)
			std::cerr << "ERROR: Print_Matrix(): " << "Invalid Size of Matrix: " << dimensions << std::endl; 
		
	int strln = nametoken.size();
	std::string Heading(strln+3, " "); //3 => _=_ : "_" is whitespace
	std::string Name(nametoken);
	Name.append(" = ");

	//Calculation of position of Name wrt to Heading Spaces


	//

		std::ostringstream buffer;

		for(int k = 0; k < dims.at(2); k++)
		{
			for(int j = 0; j < dims.at(1); j++)
			{
				buffer << Heading;
				buffer << "|  ";
				for(int i = 0; i < dims.at(0); i++)
				{
					buffer << arrptr[i][j][k] << "  ";
				}
				buffer << "|\n";
			}
			buffer << "\n\n\n";
		}
	}*/


	//9
	bool WriteBufferToFile(std::string path, std::stringstream &buffer, unsigned int precision = -1)
	{
		std::fstream file(path, ios::out);
		if(file.is_open())
		{
			if(precison = -1)
				precision = __OUT_PRECISION__;
			file << std::setprecision(precision);
			file << buffer.rdbuf();
			file.close();
			return true;
		}

		else
			return false;
		
	}


	inline void AnyKeyPress()
	{
		std::cin.get();
		cin.sync(); //Clear std::in Buffer
	}

	inline bool YN()
	{
		std::cout << "Press Y to accept and N to reject." << std::endl;
		char t = std::cin.get();
		if(t == 'y' | t == 'Y')
		{
			std::cout << "Accepted (Y)!" << std::endl;
			return true;
		}

		else if(t == 'n' | t == 'N')
		{
			std::cout << "Rejected (N)!" << std::endl;
			return false;		
		}

		else
		{
			//*** Recursive State
			std::cout << "Invalid Character Entry!" << std::endl;
			YN();	
		}
		
	} //End of YN()


}; //End of namespace Utility

#undef __OUT_PRECISION__