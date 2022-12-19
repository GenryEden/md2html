//
// Created by hdefalt on 05.12.22.
//

#ifndef REGEXMDTOHTML_DOCPART_H
#define REGEXMDTOHTML_DOCPART_H

/**
 * struct which contains indices of a part of Markdown document
 */
struct DocPart {
public:
    /**
     * index of a start of a part in document
     */
    long start;
    /**
     * length of a part
     */
    long len;

    /**
     * @param start - index of start of a part in document
     * @param len - length of a part
     */
    DocPart(long start, long len) : start(start), len(len) {}
};

#endif //REGEXMDTOHTML_DOCPART_H
