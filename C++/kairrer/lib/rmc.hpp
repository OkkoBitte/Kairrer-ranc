/*

 RUN MACHINE COMMAND

*/
#include <vector>
#include <string>
#include <sys/mman.h>
#include <memory>
#include <cstring> 
#include <iostream>
class rmc {
    public:
        static void run(const std::string& hexStr) {
            
            std::vector<uint8_t> code = hexStringToBytes(hexStr);
            
            // if(code.empty() || code.back() != 0xC3)  code.push_back(0xC3); 
            
    
            
            size_t size = std::max(code.size(), static_cast<size_t>(4096));
            void* mem = mmap(nullptr, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
            
            if(mem == MAP_FAILED) {
                perror("mmap failed");
                return;
            }
    
            
            memcpy(mem, code.data(), code.size());
    
            mprotect(mem, code.size(), PROT_READ | PROT_EXEC);
    
    
            try {
                using FuncPtr = void(*)();
                FuncPtr func = reinterpret_cast<FuncPtr>(mem);
                func();
            } catch(...) {
                std::cerr << "Execution failed" << std::endl;
            }
    
    
            munmap(mem, size);
        }
    
    private:
        static std::vector<uint8_t> hexStringToBytes(const std::string& hexStr) {
            std::vector<uint8_t> bytes;
            std::string cleanHex;
            for(char c : hexStr) {
                if(isxdigit(c)) cleanHex += tolower(c);
            }

            if(cleanHex.length() % 2 != 0) throw std::runtime_error("Invalid hex string length");
            
            for(size_t i = 0; i < cleanHex.length(); i += 2) {
                std::string byteStr = cleanHex.substr(i, 2);
                uint8_t byte = static_cast<uint8_t>(std::stoul(byteStr, nullptr, 16));
                bytes.push_back(byte);
            }

            return bytes;
        }
};