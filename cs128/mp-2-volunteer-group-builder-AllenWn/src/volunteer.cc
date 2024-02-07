#include "volunteer.hpp"
#include <string>

Volunteer::Volunteer(const std::string& nm, int b_e, int p_s, bool ret) {
    if (b_e < 0) {
        building_experience = 0;
    } else if (b_e > 10) {
        building_experience = 10;
    } else {
        building_experience = b_e;
    }
    if (p_s < 0) {
        physical_stamina = 0;
    } else if (p_s > 10) {
        physical_stamina = 10;
    } else {
        physical_stamina = p_s;
    }
    
    returing = ret;
    name = nm;
}

std::string Volunteer::GetName() const {
    return name;
}

int Volunteer::GetBuildingExperience() const {
    return building_experience;
}

int Volunteer::GetPhysicalStamina() const {
    return physical_stamina;
}

bool Volunteer::IsReturning() const {
    return returing;
}