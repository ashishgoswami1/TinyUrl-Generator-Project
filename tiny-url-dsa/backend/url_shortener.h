#ifndef URL_SHORTENER_H
#define URL_SHORTENER_H

#include <string>
#include <unordered_map>

class URLShortener {
private:
    std::unordered_map<std::string, std::string> longToShort;
    std::unordered_map<std::string, std::string> shortToLong;
    std::string characters;
    int id;

    std::string encode(int num);
    int decode(const std::string& shortURL);

public:
    URLShortener();
    std::string shortenURL(const std::string& longURL);
    std::string expandURL(const std::string& shortURL);
};

#endif
