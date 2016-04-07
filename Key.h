//
// Created by bandit on 4/7/16.
//

#ifndef FIRST_KEY_H
#define FIRST_KEY_H


class Key {
int x,y;
public:
    Key(int,int);
    int getX();
    int getY();
    bool operator==(const Key&) const;
    ~Key(){}
};


#endif //FIRST_KEY_H
