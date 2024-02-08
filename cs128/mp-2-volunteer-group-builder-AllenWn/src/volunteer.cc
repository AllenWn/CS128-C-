#include "volunteer.hpp"
#include <string>

Volunteer::Volunteer(const std::string& name, int building_experience, int physical_stamina, bool returning) {

    const int kMax = 10;

    if (building_experience < 0) {
        building_experience_ = 0;
    } else if (building_experience > kMax) {
        building_experience_ = kMax;
    } else {
        building_experience_ = building_experience;
    }
    if (physical_stamina < 0) {
        physical_stamina_ = 0;
    } else if (physical_stamina > kMax) {
        physical_stamina_ = kMax;
    } else {
        physical_stamina_ = physical_stamina;
    }
    
    returing_ = returning;
    name_ = name;
}

std::string Volunteer::GetName() const {
    return name_;
}

int Volunteer::GetBuildingExperience() const {
    return building_experience_;
}

int Volunteer::GetPhysicalStamina() const {
    return physical_stamina_;
}

bool Volunteer::IsReturning() const {
    return returing_;
}