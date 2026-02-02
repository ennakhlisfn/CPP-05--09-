#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& other){
    (void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe(){}


void PmergeMe::sortVector(std::vector<int>& v) {
    if (v.size() <= 1) return;

    int leftover = -1;
    bool hasLeftover = false;
    if (v.size() % 2 != 0) {
        leftover = v.back();
        v.pop_back();
        hasLeftover = true;
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < v.size(); i += 2) {
        if (v[i] < v[i + 1]) std::swap(v[i], v[i + 1]);
        pairs.push_back(std::make_pair(v[i], v[i + 1]));
    }

    std::sort(pairs.begin(), pairs.end()); 

    std::vector<int> mainChain;
    std::vector<int> pend;
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    mainChain.insert(mainChain.begin(), pend[0]);

    for (size_t i = 1; i < pend.size(); ++i) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
        mainChain.insert(it, pend[i]);
    }

    if (hasLeftover) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(it, leftover);
    }

    v = mainChain;
}


void PmergeMe::sortDeque(std::deque<int>& d) {
    if (d.size() <= 1) return;

    int leftover = -1;
    bool hasLeftover = false;
    if (d.size() % 2 != 0) {
        leftover = d.back();
        d.pop_back();
        hasLeftover = true;
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < d.size(); i += 2) {
        if (d[i] < d[i + 1])
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
        else
            pairs.push_back(std::make_pair(d[i], d[i + 1]));
    }

    std::sort(pairs.begin(), pairs.end());

    std::deque<int> mainChain;
    std::deque<int> pend;

    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    mainChain.push_front(pend[0]);

    for (size_t i = 1; i < pend.size(); ++i) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
        mainChain.insert(it, pend[i]);
    }
    if (hasLeftover) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(it, leftover);
    }

    d = mainChain;
}