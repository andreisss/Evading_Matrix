#include <stdio.h>
#include <intrin.h>

void check_hypervisor()
{
    int cpuInfo[4] = { 0 };

    // Call cpuid with eax = 1 to check if a hypervisor is present
    __cpuid(cpuInfo, 1);

    // Check the 31st bit of ecx to see if a hypervisor is present
    if (cpuInfo[2] & (1 << 31))  // If bit 31 of ecx is set, a hypervisor is present
    {
        printf("Hypervisor detected (possibly VMware or another virtualized environment)!\n");
    }
    else
    {
        printf("No hypervisor detected. Running on physical hardware.\n");
    }
}

int main()
{
    check_hypervisor();
    return 0;
}
