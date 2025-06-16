#include <iostream>
#include <fstream>

class FileReader {
public:
    virtual ~FileReader() {}

    virtual void Display(const char* path) {
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cout << "[Error] Cannot open file: " << path << "\n";
            return;
        }

        std::cout << "[Text Display] File content:\n";
        char ch;
        while (file.get(ch)) {
            std::cout << ch;
        }
        std::cout << "\n";
        file.close();
    }
};

class AsciiFileReader : public FileReader {
public:
    void Display(const char* path) override {
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cout << "[Error] Cannot open file: " << path << "\n";
            return;
        }

        std::cout << "[ASCII Display] Character ASCII codes:\n";
        char ch;
        while (file.get(ch)) {
            std::cout << static_cast<int>(static_cast<unsigned char>(ch)) << " ";
        }
        std::cout << "\n";
        file.close();
    }
};

class BinaryFileReader : public FileReader {
public:
    void Display(const char* path) override {
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cout << "[Error] Cannot open file: " << path << "\n";
            return;
        }

        std::cout << "[Binary Display] Binary representation:\n";
        char ch;
        while (file.get(ch)) {
            unsigned char byte = static_cast<unsigned char>(ch);
            for (int i = 7; i >= 0; --i) {
                std::cout << ((byte >> i) & 1);
            }
            std::cout << " ";
        }
        std::cout << "\n";
        file.close();
    }
};

int main() {
    const char* filepath = "test.txt";

    FileReader* reader;

    std::cout << "--- Base class (text) ---\n";
    reader = new FileReader();
    reader->Display(filepath);
    delete reader;

    std::cout << "\n--- AsciiFileReader ---\n";
    reader = new AsciiFileReader();
    reader->Display(filepath);
    delete reader;

    std::cout << "\n--- BinaryFileReader ---\n";
    reader = new BinaryFileReader();
    reader->Display(filepath);
    delete reader;

    return 0;
}
