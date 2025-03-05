#include "FileManager.h"
#include "Utils.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <algorithm>

namespace CatNip
{
    void FileManager::PushToFileManager(std::filesystem::path filePathName, std::string data)
    {
        std::string fileName = filePathName.filename();
        std::string filePath = filePathName;

        for (auto& [key , fileData] : m_Files)
        {
            if(key == filePath && fileData.IsOpen)
            {
                Utils::PrintWarning("File is already opened!");
                return;
            }
        }

        std::ifstream in(filePath, std::ios::binary);
        if (!in.is_open())
        {
            Utils::PrintError("File does not exist!");
            return;
        }

        FileData fileData;

        in.seekg(0, std::ios::end);
        std::streamsize size = in.tellg();
        in.seekg(0, std::ios::beg);

        if (size > 0)
        {
            fileData.Content = data;
        }
        else
        {
            in.close();
        }

        fileData.Title = fileName;
        fileData.AbsoluteFilePath = filePath;
        fileData.IsOpen = true;


        m_Files.emplace(filePath, fileData);
    }

    void FileManager::RemoveFileFromIndex(const std::string& key)
    {
        m_Files.erase(key);
    }

    void FileManager::SaveFile(const std::filesystem::path& filePath, char* inData)
    {
         auto& fileData = m_Files.at(filePath);

         std::string dataString(inData);

         if (fileData.Content == dataString)
             return;

         std::string saveData(inData);

         std::ifstream in(filePath);
         if (!in.is_open())
         {
             Utils::PrintError("File does not exist anymore, Creating new file at that location!");
         }
         in.close();

        std::ofstream out(filePath);
        if (!out.is_open())
        {
            Utils::PrintError("Could not open/generate file at that location!");
            return;
        }
        out << saveData;
        out.close();

    }

    std::string FileManager::GetFileData(const std::filesystem::path& filePathName)
    {
        std::ifstream in(filePathName);
        if (in.is_open())
        {
            std::stringstream out;
            out << in.rdbuf();
            return out.str();
        }

        Utils::PrintError("Could not get Data!");
        return std::string();
    }
}
