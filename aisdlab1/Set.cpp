

#include "Set.h"
#include <iostream>

Set::Set(const Set & second) {
    size = second.size;
    arr = second.arr;
}

Set::~Set() {
    if (!arr)
        delete[] arr;
}


int Set::operator[](const int index) { 
    if (!arr)
        throw std::logic_error("arr == nullptr");
    if (index > size - 1 || index < 0)   
        throw std::logic_error("invalide index");
    return arr[index];
}


Set Set::operator+(const Set& second) { 
    Set res(size + second.size);
    res.size = 0;
    for (int i = 0; i < size; i++) {
        res.arr[i] = arr[i];
        res.size++;
    }
    for (int i = 0; i < second.size; i++) {
        if (check_num(second.arr[i]) == false)
        {
            res.arr[res.size] = second.arr[i];
            res.size++;
        }
    }
    return res;
}


Set Set::operator-(const Set& second) {
    Set res(size);
    res.size = 0;
    bool flag = false;
    for (int i = 0; i < size; i++) {
        flag = false;
        for (int j = 0; j < second.size; j++) {
            if (arr[i] == second.arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            res.arr[res.size] = arr[i];
            res.size++;
        }
    }
    return res;
}

Set Set::operator+(int num) { 
    if (!arr)
    {
        Set arr_n(size);
        arr_n.arr[0] = num;
        arr_n.size++;
        return arr_n;

    }
    else {
        if (check_num(num) == false)
        {
            Set arr_n(size + 1);
            for (int i = 0; i < size; i++) {
                arr_n.arr[i] = arr[i];
            }
            arr_n.arr[size] = num;
            return arr_n;
        }
    }
}

Set Set::operator-(int num)
{
    Set arr_n(size);
    for (int i = 0; i < arr_n.size; i++) { 
        arr_n.arr[i] = arr[i];
    }
    for (int i = 0; i < arr_n.size; i++) {
        if (arr_n.arr[i] == num)
        {
            for (int j = i; j < arr_n.size - 1; j++) {
                arr_n.arr[j] = arr_n.arr[j + 1];
            }
            arr_n.size--;
            break;
        }
        else throw ("Set have not got this num");
    }
    return arr_n;
}

Set& Set::operator+=(int num) 
{
    if (!arr)
    {
        Set tmp(size);
        tmp.arr[0] = num;
        arr = tmp.arr;
        size++;

    }
    if (check_num(num) == false) {
        Set tmp(size);
        for (int i = 0; i < size; i++) {
            tmp.arr[i] = arr[i];
        }
        tmp.arr[tmp.size] = num;
        arr = tmp.arr;
        size++;
    }
    return *this;
}

Set& Set::operator-=(int num) { 
    if (check_num(num) == false)
        throw std::logic_error("Set have not got this num");
    for (int i = 0; i < size; i++) {
        if (arr[i] == num)
        {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            break;
        }
    }
    return *this;
}

Set Set::intersection(const Set& second) {
    Set res(size);
    res.size = 0;
    bool flag = false;
    for (int i = 0; i < size; i++) {
        flag = false;
        for (int j = 0; j < second.size; j++) {
            if (arr[i] == second.arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            res.arr[res.size] = arr[i];
            res.size++;
        }
    }
    return res;
}



bool Set::operator==(const Set& second) { 
    if (second.size != size)
        return false;
    else
    {
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            flag = false;
            for (int j = 0; j < second.size; j++) 
            {
                if (arr[i] == second.arr[j]) {
                    flag = true;
                }
            }
            if (flag == false)
                return false;
        }
        return true;
    }
}

bool Set::operator!=(const Set& second) {
    if (second.size != size)
        return true;
    else
    {
        bool flag = true;
        for (int i = 0; i < size; i++)
        {
            flag = true;
            for (int j = 0; j < second.size; j++) {
                if (arr[i] == second.arr[j]) {
                    flag = false;
                }
            }
            if (flag == true)
                return true;
        }
        return false;
    }
}
bool Set::check_count(const Set& second) {
    if (!arr)
        throw std::logic_error("arr == nullptr");
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        flag = false;
        for (int j = 0; j < second.size; j++) {
            if (arr[i] == second.arr[j])
                flag = true;
        }
        if (flag == false)
            return false;
    }
    return true;
}
bool Set::check_num(int num) { 
    if (!arr)
        throw std::logic_error("arr == nullptr in check_num");
    for (int i = 0; i < size; i++) {
        if (num == arr[i])
            return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& s, const Set& set) 
{
    for (int i = 0; i < set.size; i++) {
        s << set.arr[i] << " ";
    }
    return s;
}
