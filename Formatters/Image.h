//
// Created by hdefalt on 06.12.22.
//

#ifndef REGEXMDTOHTML_IMAGE_H
#define REGEXMDTOHTML_IMAGE_H


#include "AbstractFormatter.h"

/**
 * Context of format for image
 */
class Image : public AbstractFormatter {
public:
    DocPart findMatch(const std::string &markdown) override;

    std::string toHTML(const std::string &markdown) override;

private:
    static std::regex regular;
};


#endif //REGEXMDTOHTML_IMAGE_H
