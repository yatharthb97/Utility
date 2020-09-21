#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <iomanip>
#include <stdio.h> 
#include <cstdio>
#include <bits/stdc++.h>
#include <random>
#include <string>
#include <sys/stat.h>

#define __OUT_PRECISION__ 16

namespace File
{


	//1a
	void inline LineByLine(std::string &FILE)
	{
		const char* FILENAME = FILE.c_str();
		FILE* fp = fopen(FILENAME, "r");
		if (fp == NULL)
		    exit(EXIT_FAILURE);

		char* line = NULL;
		size_t len = 0;
		while ((getline(&line, &len, fp)) != -1) {
		    // using printf() in all tests for consistency
		    printf("%s", line);
		}
		fclose(fp);
		if (line)
		    free(line);
	}  //End of LineByLine()

	//1b
	void inline LineByLine(std::string &FILE, int no)
	{
		const char* FILENAME = FILE.c_str();
		FILE* fp = fopen(FILENAME, "r");
		if (fp == NULL)
		    exit(EXIT_FAILURE);

		char* line = NULL;
		size_t len = 0;
		
		for(int i = no; i>0; i--)
		{
			if(getline(&line, &len, fp)) != -1) 
			{
			    // using printf() in all tests for consistency
			    printf("%s", line);
			}
		}

		fclose(fp);
		if (line)
		    free(line);
	} //End of LineByLine() Overload

	//2a
	void ShuffleLines(std::string &FILE)
	{
		unsigned int size = File::LineCount(FILE);
		std::vector<std::string> vec;
		vec.reserve(size);
		std::ifstream file(FILE);
		std::string line;
		for(unsigned int i = 0; i < size; i++)
		{
			
			std::getline(line, file);
			vec.emplace_back(line);
		}
		file.close();

		//Shuffle
		std::random_device s;
		std::mt19937 rndeng(s());
		std::shuffle(vec.begin(), vec.end(), rndeng);

		std::stringstream buffer;
		for(unsigned int i = 0; i < size; i++)
		{
			buffer << vec.at(i) << "\n";
		}

		//Copy to temporary file
		std::string temppath = FILE + "t";
		File::SetFile(temppath, buffer.str());

		File::Remove(FILE); //Delete Old file
		File::Rename(temppath, path);


	} //End of ShuffleLines()

	//2b
	template <typename T>
	void ShuffleLines(std::string &FILE, T(*dn_RND)())
	{
		unsigned int size = File::LineCount(FILE);
		std::vector vec;
		vec.reserve(size);
		std::ifstream file(FILE);
		std::string line;
		for(unsigned int i = 0; i < size; i++)
		{
			
			std::getline(line, file);
			vec.emplace_back(line);
		}
		file.close();

		//Shuffle
		std::mt19937 rndeng;
		std::shuffle(vec.begin(), vec.end(), dn_RND);

		std::stringstream buffer;
		for(unsigned int i = 0; i < size; i++)
		{
			buffer << vec.at(i) << "\n";
		}

		//Copy to temporary file
		std::string temppath = FILE + "t";
		File::SetFile(temppath, buffer.str());

		File::Remove(FILE); //Delete Old file
		File::Rename(temppath, FILE);

	} //End of ShuffleLines() overloaded

	//3a
	bool SetFile(const std::string &path, const std::string &content)
	{
		std::ofstream file(path, std::ios::out);
		if(file.is_open())
		{
			file << content;
			file.close();
			return true;
		}

		else
			return false;
	} //End of SetFile()

	//3b
	bool SetFile(const std::string &path, const std::stringstream &content)
	{
		std::ofstream file(path, std::ios::out);
		if(file.is_open())
		{
			file << content.str();
			file.close();
			return true;
		}

		else
			return false;
	} //End of SetFile() overloaded

	//4
	//Count the number of lines in the file
	int inline LineCount(std::string &FILEPath)
	{
		int number_of_lines = 0;
	    FILE *infile = fopen(FILEPath, "r");
	    int ch;

	    while (EOF != (ch=getc(infile)))
	        if ('\n' == ch)
	            ++number_of_lines;

	    fclose(infile);
	    return number_of_lines;

	} //End of LineCount()

	//5
	void inline Remove(std::string &FILE); //Delete Old file
	{
		remove(FILE.c_str());

	} //End of void Remove()

	//6
	void inline Rename(std::string &temppath, std::string &path)
	{
		rename(temppath.c_str(), path.c_str());
	} //End of Rename()

	//7
	bool Del_line(std::string &FILE, int lineno)
	{
		std::ofstream file(FILE, std::ios::out);

		std::stringstream out;
		int counter = 0;
		std::string line;

		while(!file.eof())
		{
			counter++;
			std::getline(file, line);
			if(counter != lineno)
			{
				out << line << "\n";
			}

		}
		file.close();

		if(lineno <= lineno)
		{
			std::string temppath = FILE + "t";
			File::SetFile(temppath, out.str());

			File::Remove(FILE); //Delete Old file
			File::Rename(temppath, FILE);
			return true;
		}

		else
			return false;

	} //End of Del_line()

	//8
	inline bool exists(const std::string &name) 
	{
	  struct stat buffer;   
	  return (stat (name.c_str(), &buffer) == 0); 
	} //End of exists()

	//9
	bool WriteBufferToFile(std::string path, std::stringstream &buffer, unsigned int precision = -1)
	{
		std::ofstream file(path, std::ios::out);
		if(file.is_open())
		{
			if(precision = -1)
				precision = __OUT_PRECISION__;
			file << std::setprecision(precision);
			file << buffer.rdbuf();
			file.close();
			return true;
		}

		else
			return false;
		
	} //End of WriteBufferToFile()


	//10a
	bool AppFile(const std::string &path, const std::string &content)
	{
		std::ofstream file(path, std::ios::app);
		if(file.is_open())
		{
			file << content;
			file.close();
			return true;
		}

		else
			return false;
	} //End of AppFile()

	//10b
	bool AppFile(const std::string &path, const std::stringstream &content)
	{
		std::ofstream file(path, std::ios::app);
		if(file.is_open())
		{
			file << content.str();
			file.close();
			return true;
		}

		else
			return false;
	} //End of AppFile() overloaded


	//11
	std::string GetLine(std::string &FILE, int lineno)
	{
		std::ofstream file(FILE, std::ios::out);
		int counter = 0;
		while(!file.eof())
		{
			counter++;
			std::getline(file, line);
			if(counter == lineno)
			{
				return line;
			}

		}
		file.close();
		return std::string("");
	} //End of GetLine()

}; //End of Namespace FILE

//--------------End of Translation Unit-------------------

#undef __OUT_PRECISION__