#include <iostream>
#include "group.hpp"
#include "volunteer.hpp"

void Group::AddVolunteer(const Volunteer& volunteer) {
    volunteers.push_back(volunteer);
}

void Group::RemoveVolunteer(const Volunteer& volunteer) {
    auto it = std::find_if(volunteers.begin(), volunteers.end(),
                           [&volunteer](const Volunteer& v) {
                               return v.GetName() == volunteer.GetName(); 
                           });
    if (it != volunteers.end()) { 
        volunteers.erase(it); 
    }
}

double Group::GetAvgBuildingExp() const {
    if (volunteers.size() == 0) {
        return 0;
    }
    double total = 0;
    for (const auto& vol : volunteers) {
        total += vol.GetBuildingExperience();
    }
    double result = total / volunteers.size();
    return result;
}

double Group::GetAvgStamina() const {
    if (volunteers.size() == 0) {
        return 0;
    }
    double total = 0;
    for (const auto& vol : volunteers) {
        total += vol.GetPhysicalStamina();
    }
    double result = total / volunteers.size();
    return result;
}

int Group::GetReturningMembers() const {
    int count = 0;
    for (const auto& vol : volunteers) {
        if (vol.IsReturning()) {
            count++;
        }
    }
    return count;
}

Volunteer& Group::GetRandomVolunteer() {
    int i = rand() % volunteers.size();
    return volunteers[i];
}

std::ostream& operator<<(std::ostream& os, const Group& g_in) {
    os << "XP:" << g_in.GetAvgBuildingExp() << ", ST:" << g_in.GetAvgStamina() << ", RET:" << g_in.GetReturningMembers() <<std::endl;
    for (const auto& volunteer : g_in.volunteers) {
        os << volunteer.GetName() << std::endl;
    }
    return os;
}
