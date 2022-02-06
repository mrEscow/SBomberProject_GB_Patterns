#pragma once
#include <iostream>
#include <string>
#include <vector>

// T=it U=obj
template <typename T, typename U>
class BombIterator {
public:
    typedef typename std::vector<T>::iterator iter_type;
    BombIterator(U* p_data, bool reverse = false) : m_p_data_(p_data) {
        m_it_ = m_p_data_->m_data_.begin();
    }

    void First() {
        m_it_ = m_p_data_->m_data_.begin();
    }

    void Next() {
        m_it_++;
    }

    bool IsDone() {
        return (m_it_ == m_p_data_->m_data_.end());
    }

    iter_type Current() {
        return m_it_;
    }

private:
    U* m_p_data_;
    iter_type m_it_;

};

template <class T>
class BombContainer {
    friend class BombIterator<T, BombContainer>;

public:
    void Add(T a) {
        m_data_.push_back(a);
    }

    BombIterator<T, BombContainer>* CreateIterator() {
        return new BombIterator<T, BombContainer>(this);
    }

private:
    std::vector<T> m_data_;
};
