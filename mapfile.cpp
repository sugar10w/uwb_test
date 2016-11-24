#include <mapfile.h>

HANDLE hMap_pos;
HANDLE hMap_target;

void MapFileInit()
{
    LPCWSTR strMapName_pos = L"ZeroTechDobbyPos";
    LPCWSTR strMapName_target = L"ZeroTechDobbyTarget";

    /* 尝试打开 */
    hMap_pos = OpenFileMapping(FILE_MAP_ALL_ACCESS, 0, strMapName_pos);
    hMap_target = OpenFileMapping(FILE_MAP_ALL_ACCESS, 0, strMapName_target);
    if (NULL == hMap_pos)
    {
        /* 打开失败, 开始创建 */
        hMap_pos = CreateFileMapping(
            INVALID_HANDLE_VALUE,
            NULL,
            PAGE_READWRITE,
            0,
            100,
            strMapName_pos
            );
    }
    if (NULL == hMap_target)
        hMap_target = CreateFileMapping(
            INVALID_HANDLE_VALUE,
            NULL,
            PAGE_READWRITE,
            0,
            100,
            strMapName_target
            );

}
