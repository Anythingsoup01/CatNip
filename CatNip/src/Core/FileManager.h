#pragma once

#include <cstddef>
#include <vector>
#include <string>
#include <unordered_map>
#include <filesystem>

namespace CatNip
{

    const size_t k_MaxBufferSize = 4096;


    struct FileData
    {
        std::string Title;
        std::filesystem::path AbsoluteFilePath;
        std::string Content;
        char Buffer[65536];
        bool IsOpen = false;
    };

    struct FolderData
    {
        bool InFolder = false;

        std::string Title;
        std::filesystem::path AbsoluteFolderPath;
    };

    class FileManager
    {
    public:
        FileManager() {}
        ~FileManager()
        {
        }

        void PushToFileManager(std::filesystem::path filePathName, std::string data);
        void RemoveFileFromIndex(const std::string& key);

        void SaveFile(const std::filesystem::path& filePath, char* inData);

        static std::string GetFileData(const std::filesystem::path& filePathName);

        std::unordered_map<std::string, FileData> m_Files;
        FolderData m_Folder;

    private:

    };
}
