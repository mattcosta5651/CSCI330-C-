#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>

class FileReader
{
public:
    FileReader(const std::string& file);
    virtual ~FileReader();
	bool endOfFile();
	bool exists();
    std::string readLine();
    
private:
    std::ifstream m_input;
};

#endif
    
    