#include <iostream>
#include "group.hpp"
#include "volunteer.hpp"

void Group::AddVolunteer(const Volunteer& volunteer) {
    volunteers_.push_back(volunteer);
}

void Group::RemoveVolunteer(const Volunteer& volunteer) {
    auto it = std::find_if(volunteers_.begin(), volunteers_.end(),
                           [&volunteer](const Volunteer& v) {
                               return v.GetName() == volunteer.GetName(); 
                           });
    if (it != volunteers_.end()) { 
        volunteers_.erase(it); 
    }
}

double Group::GetAvgBuildingExp() const {
    if (volunteers_.empty()) {
        return 0;
    }
    double total = 0;
    for (const auto& vol : volunteers_) {
        total += vol.GetBuildingExperience();
    }
    double result = total / static_cast<double>(volunteers_.size());
    return result;
}

double Group::GetAvgStamina() const {
    if (volunteers_.empty()) {
        return 0;
    }
    double total = 0;
    for (const auto& vol : volunteers_) {
        total += vol.GetPhysicalStamina();
    }
    double result = total / static_cast<double>(volunteers_.size());
    return result;
}

int Group::GetReturningMembers() const {
    int count = 0;
    for (const auto& vol : volunteers_) {
        if (vol.IsReturning()) {
            count++;
        }
    }
    return count;
}

Volunteer& Group::GetRandomVolunteer() {
    int i = rand() % static_cast<int>(volunteers_.size());
    return volunteers_[i];
}

std::ostream& operator<<(std::ostream& os, const Group& g_in) {
    os << "XP:" << g_in.GetAvgBuildingExp() << ", ST:" << g_in.GetAvgStamina() << ", RET:" << g_in.GetReturningMembers() <<std::endl;
    for (const auto& volunteer : g_in.volunteers_) {
        os << volunteer.GetName() << std::endl;
    }
    return os;
}
