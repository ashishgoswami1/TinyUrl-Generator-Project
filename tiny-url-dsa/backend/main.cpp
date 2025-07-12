#include <iostream>
#include "url_shortener.h"

int main() {
    URLShortener shortener;

    std::string longURL;
    std::cout << "Enter a long URL: ";
    std::cin >> longURL;

    std::string shortURL = shortener.shortenURL(longURL);
    std::cout << "Short URL: " << shortURL << std::endl;

    std::string expandedURL = shortener.expandURL(shortURL);
    std::cout << "Expanded URL: " << expandedURL << std::endl;

    return 0;
}
