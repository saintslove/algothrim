/*
 * FileCount.cpp
 *
 *  Created on: 2016年12月2日
 *      Author: wangqi
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cctype>
#include <memory>


int Count()
{
	std::fstream file("copyout",std::fstream::in|std::fstream::out|std::fstream::ate);
	if(!file){
		std::cout<<"file open fail"<<std::endl;
		return EXIT_FAILURE;
	}
	std::fstream::pos_type endmark = file.tellg();
	file.seekg(0,std::fstream::beg);
	std::string line;
	std::size_t count = 0;
	while(file && (file.tellg() != endmark) && std::getline(file,line)){
		count += line.size()+1;
		std::fstream::pos_type current = file.tellg();
		file.seekp(0,std::fstream::end);
		file << count;
		if(current != endmark)
			file<<" ";
		file.seekg(current);
	}
	file.seekp(0,std::fstream::end);
	file<<"\n";
	return count;
	return 0;

	//		std::fstream::int_type c;
	//	while((c = file.get()) != EOF){
	//		file.put(c);
	//	}


		std::string s("dadasdeawed");
		decltype(s.size()) count = 0;
		for(auto &a : s){
			if(std::ispunct(a))
				++count;
			if(std::islower(a))
				std::toupper(a);
		}



}


