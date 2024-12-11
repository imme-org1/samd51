/*******************************************************************************
  File Name:
    app_mem.c

  Summary:
    Serial flash memory task.

  Description:
 *******************************************************************************/
#include "app_mem.h"

// .............................................................................

static uint8_t CACHE_ALIGN fswork[512];

int dbg_fileSize = 0;           // !dbg!
uint8_t dbg_file_cntr = 0;      // !dbg!
char dbg_str_1[] = "[Here is some data 0123456789]";
char dbg_str_2[] = "[Here is MORE data 9876543210]";
char dbg_str_X[512];
int dbg_res = 0;
uint8_t dbg_data_1[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2};
uint8_t dbg_data_2[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
uint8_t dbg_data_X[512];
uint8_t dbg_data_Big1[4096];
uint8_t dbg_data_Big2[4096];
#define MEM_TEST_SIZE 128
uint8_t dbg_data_Small_1[MEM_TEST_SIZE];
uint8_t dbg_data_Small_2[MEM_TEST_SIZE];
uint8_t dbg_data_Small_3[MEM_TEST_SIZE];
uint8_t dbg_mem_brk = 0;
uint16_t dbg_mem_total_cntr = 0;
uint16_t dbg_mem_good_cntr = 0;
uint16_t dbg_mem_bad_cntr = 0;

const char flash_dev_name[] = "/dev/mtda1";
const char flash_mount_name[] = "/mnt/mem1";

#define MAX_DATA_WRITE_LEN 512

// .............................................................................

void dump(uint8_t *buf, int len)
{
#if 1    
    DBGprintf("dump:\n");
    for (int i = 0; i < len; i++) {
        DBGprintf("%02X ", buf[i] & 0xFF);
        if ((i & 0x0F) == 0x0F) {
            DBGprintf("\n");
        }
    }
    DBGprintf("\n");
#endif
}

// .............................................................................
// Read the filenames of all the files in the specified directory
// .............................................................................
void app_mem_read_dir() 
{
    SYS_FS_FSTAT fileStatus;

    // Open the directory
    SYS_FS_HANDLE dirHandle = SYS_FS_DirOpen("/mnt/mem1");

    if (dirHandle != SYS_FS_HANDLE_INVALID) {

        // Read each file in the directory
        while (SYS_FS_DirRead(dirHandle, &fileStatus) == SYS_FS_RES_SUCCESS) {
            if (fileStatus.fname[0] == '\0') break;  // End of directory
            printf("File: %s\n", fileStatus.fname);   // Display or process file names
            dbg_file_cntr++;        // !dbg!
        }

        // Close the directory
        SYS_FS_DirClose(dirHandle);
    } else {
        // Handle error in opening directory
    }

}
// .............................................................................
// See if a particular file exists
// e.g. filePath = "/mnt/mem1/text1.txt"
// .............................................................................
bool app_mem_file_exists(const char *filePath) {
    SYS_FS_FSTAT fileStatus;
    
    // Check the file status
    if (SYS_FS_FileStat(filePath, &fileStatus) == SYS_FS_RES_SUCCESS) {
        // File exists
        return true;
    } else {
        // File does not exist
        return false;
    }
}
// .............................................................................
// Write to a file (overwrite if already exists)
// .............................................................................
void app_mem_file_write_ch(const char *filePath, char *data_to_w) 
{
    int c;
    int len;
    SYS_FS_HANDLE fileHandle;
    
    len = strlen(data_to_w);

    strcpy((char *)fswork, data_to_w);
    fileHandle = SYS_FS_FileOpen(filePath, (SYS_FS_FILE_OPEN_WRITE));
    c = SYS_FS_FileWrite(fileHandle, (const void *)fswork, len);
    SYS_FS_FileClose(fileHandle);
}
// .............................................................................
// Append to a file (create if it doesn't exists)
// .............................................................................
int app_mem_file_app_ch(char *fileName, char *data_to_w) 
{
    int res;
    int len;
    SYS_FS_HANDLE fileHandle;
    char fullPath[100];
    size_t required_path_length;
    
    // FIRST - verify can go ahead with the operation
    
    // Check if fileName is NULL or empty
    if (fileName == NULL || fileName[0] == '\0') {
        // Filename is null or empty
        return -1;
    }
    // Check if data_to_w is NULL
    if (data_to_w == NULL) {
        // data_to_w is NULL
        return -2;
    }
    // Calculate the required path length and check for overflow
    required_path_length = strlen(flash_mount_name) + 1 + strlen(fileName) + 1;
    if (required_path_length > sizeof(fullPath)) {
        // Full path exceeds buffer size
        return -3;
    }    
    
    // SECOND: Operate!
    
    // Combine mount name and file name into full_path
    snprintf(fullPath, sizeof(fullPath), "%s/%s", flash_mount_name, fileName);    
    
    len = strlen(data_to_w);
    
    strcpy((char *)fswork, data_to_w);
//    fileHandle = SYS_FS_FileOpen(filePath, (SYS_FS_FILE_OPEN_APPEND));
    fileHandle = SYS_FS_FileOpen(fullPath, (SYS_FS_FILE_OPEN_APPEND));
    if (fileHandle == SYS_FS_HANDLE_INVALID) {
        // Invalid handle
        return -4;
    }
    res = SYS_FS_FileWrite(fileHandle, (const void *)fswork, len);
    if (res == -1) {
        // Failed to write data to file
    }
    res = SYS_FS_FileClose(fileHandle);
    if (res != SYS_FS_RES_SUCCESS) {
        // Failed to close file
        return -6;
    }
    return 0;
}
// .............................................................................
// Write to a file (overwrite if already exists)
// .............................................................................
int app_mem_file_write(char *fileName, const uint8_t *data_to_w, size_t data_len) 
{
    int res;
    int len;
    SYS_FS_HANDLE fileHandle;
    char fullPath[100];
    size_t required_path_length;
    
    // FIRST - verify can go ahead with the operation
    
    // Check if fileName is NULL or empty
    if (fileName == NULL || fileName[0] == '\0') {
        // Filename is null or empty
        return -1;
    }
    // Check if data_to_w is NULL
//    if (data_to_w == NULL) {
//        // data_to_w is NULL
//        return -2;
//    }
    if (data_len > MAX_DATA_WRITE_LEN) {
        // Invalid data length
        return -3;
    }
    // Calculate the required path length and check for overflow
    required_path_length = strlen(flash_mount_name) + 1 + strlen(fileName) + 1;
    if (required_path_length > sizeof(fullPath)) {
        // Full path exceeds buffer size
        return -4;
    }    
    
    // SECOND: Operate!
    
    // Combine mount name and file name into full_path
    snprintf(fullPath, sizeof(fullPath), "%s/%s", flash_mount_name, fileName);    
    
    len = strlen(data_to_w);
    
//    strcpy((char *)fswork, data_to_w);
    fileHandle = SYS_FS_FileOpen(fullPath, (SYS_FS_FILE_OPEN_WRITE));
    if (fileHandle == SYS_FS_HANDLE_INVALID) {
        // Invalid handle
        return -5;
    }
    res = SYS_FS_FileWrite(fileHandle, data_to_w, data_len);
//    res = SYS_FS_FileWrite(fileHandle, (const void *)fswork, len);
    if (res == -1) {
        // Failed to write data to file
    }
    res = SYS_FS_FileClose(fileHandle);
    if (res != SYS_FS_RES_SUCCESS) {
        // Failed to close file
        return -7;
    }
    return 0;
}
// .............................................................................
// Append to a file (create if it doesn't exists)
// .............................................................................
int app_mem_file_app(char *fileName, const uint8_t *data_to_w, size_t data_len) 
{
    int res;
    int len;
    SYS_FS_HANDLE fileHandle;
    char fullPath[100];
    size_t required_path_length;
    
    // FIRST - verify can go ahead with the operation
    
    // Check if fileName is NULL or empty
    if (fileName == NULL || fileName[0] == '\0') {
        // Filename is null or empty
        return -1;
    }
    // Check if data_to_w is NULL
//    if (data_to_w == NULL) {
//        // data_to_w is NULL
//        return -2;
//    }
    
    
    if ((data_len == 0) || (data_len > MAX_DATA_WRITE_LEN)) {
        // Invalid data length
        return -3;
    }
    // Calculate the required path length and check for overflow
    required_path_length = strlen(flash_mount_name) + 1 + strlen(fileName) + 1;
    if (required_path_length > sizeof(fullPath)) {
        // Full path exceeds buffer size
        return -4;
    }    
    
    // SECOND: Operate!
    
    // Combine mount name and file name into full_path
    snprintf(fullPath, sizeof(fullPath), "%s/%s", flash_mount_name, fileName);    
    
    len = strlen(data_to_w);
    
//    strcpy((char *)fswork, data_to_w);
    fileHandle = SYS_FS_FileOpen(fullPath, (SYS_FS_FILE_OPEN_APPEND));
    if (fileHandle == SYS_FS_HANDLE_INVALID) {
        // Invalid handle
        return -5;
    }
    res = SYS_FS_FileWrite(fileHandle, data_to_w, data_len);
//    res = SYS_FS_FileWrite(fileHandle, (const void *)fswork, len);
    if (res == -1) {
        // Failed to write data to file
    }
    res = SYS_FS_FileClose(fileHandle);
    if (res != SYS_FS_RES_SUCCESS) {
        // Failed to close file
        return -7;
    }
    return 0;
}
// .............................................................................
// Read contents of a file
// .............................................................................
void app_mem_file_read_ch(const char *filePath, char *data_to_r) 
{
    int c;
    int fileSize;
    SYS_FS_HANDLE fileHandle;
//    int res;

    fileHandle = SYS_FS_FileOpen(filePath, (SYS_FS_FILE_OPEN_READ));
    fileSize = SYS_FS_FileSize(fileHandle);
    dbg_fileSize = fileSize;    // !dbg!

    if (fileSize > 512) fileSize = 512;
    c = SYS_FS_FileRead(fileHandle, (void *)data_to_r, fileSize);
    SYS_FS_FileClose(fileHandle);

}
// .............................................................................
// Read contents of a file
// .............................................................................
int app_mem_file_read(const char *fileName, uint8_t *data_to_r, size_t data_size) 
{
    int c;
    int fileSize;
    SYS_FS_HANDLE fileHandle;
    int res;

    char fullPath[100];
    
    // Combine mount name and file name into full_path
    snprintf(fullPath, sizeof(fullPath), "%s/%s", flash_mount_name, fileName);  
    
    

    fileHandle = SYS_FS_FileOpen(fullPath, (SYS_FS_FILE_OPEN_READ));
    if (fileHandle == SYS_FS_HANDLE_INVALID) {
        // Failed to open file
        return -1;
    }
    fileSize = SYS_FS_FileSize(fileHandle);
    dbg_fileSize = fileSize;    // !dbg!
    if (fileSize > 512) fileSize = 512;

    c = SYS_FS_FileRead(fileHandle, data_to_r, data_size);
    
    
    if (c == -1) {
        // Failed to read data from file
    } else {
        // All okay
    }

    res = SYS_FS_FileClose(fileHandle);
    if (res != SYS_FS_RES_SUCCESS) {
        // Failed to close file
        c = -3;
    }
    return c;
}
// .............................................................................
// Delete a file (if it exists)
// .............................................................................
int app_mem_file_del(const char *fileName) 
{
    int res;
    
    res = SYS_FS_FileDirectoryRemove(fileName);
    
    return res;
}

// .............................................................................
// Empty a file
// .............................................................................
int app_mem_file_empty(char *fileName) 
{
    int res;
    uint8_t dummy;
    
    res = app_mem_file_write(fileName, &dummy, 0) ;
    
    return res;
}
// .............................................................................

/*******************************************************************************
 * Task initializations.
 * This function runs BEFORE task is created and scheduler started!.
 */
void APP_MEM_Initialize ( void )
{
}

/******************************************************************************
 * The task.
 */
void APP_MEM_Tasks ( void )
{
//    int c;
//    SYS_FS_HANDLE fileHandle;
//    int fileSize;
    char fileName1[16] = "textX.txt";
//    char fileName2[16] = "text2.txt";
//    char fileName3[16] = "text3.txt";
    int res;

    osDelayMs(100);

    /* The serial flash memory is on the 1V8 power domain of the MCU */
    while (SYS_FS_Mount(flash_dev_name, flash_mount_name, FAT, 0, NULL) != SYS_FS_RES_SUCCESS) {
        OS_SLEEP(5); //osDelayMs(5);
    }
    if (SYS_FS_Error() == SYS_FS_ERROR_NO_FILESYSTEM)
    {
        DBGprintf("/mnt/mem1 Format required\n");
        if (SYS_FS_DriveFormat("/mnt/mem1", NULL, (void *)fswork, 512) == SYS_FS_RES_FAILURE) {
            DBGprintf("/mnt/mem1 format failure!\n");
        }
        else {
            bool f;
            DBGprintf("/mnt/mem1 Format OK!\n");
            f = DRV_MX25L_Read(0, (void *)fswork, 512, 0x0000);
            DBGprintf("read [%d] at 0x0000\n", f);
            dump(fswork, 512);
        }
    }
    else {
        DBGprintf("/mnt/mem1 ok\n");
    }
    SYS_FS_CurrentDriveSet("/mnt/mem1");
    DBGprintf("current drive set = %d\n", SYS_FS_Error());
    DBGprintf("current file: %s\n", fileName1);

    
    
    /*

    osDelayMs(2000);
    strcpy((char *)fswork, "Hello file!\n");
    fileHandle = SYS_FS_FileOpen(fileName1, (SYS_FS_FILE_OPEN_APPEND));
    DBGprintf("file handle=%d, file open error=%d\n", fileHandle, SYS_FS_Error());
    c = SYS_FS_FileWrite(fileHandle, (const void *)fswork, 13);
    SYS_FS_FileClose(fileHandle);
    DBGprintf("%s 13 bytes written\n", fileName1);

        osDelayMs(2000);
        strcpy((char *)fswork, "Seeya file!\n");
        fileHandle = SYS_FS_FileOpen(fileName1, (SYS_FS_FILE_OPEN_APPEND));
        DBGprintf("file handle=%d, file open error=%d\n", fileHandle, SYS_FS_Error());
        c = SYS_FS_FileWrite(fileHandle, (const void *)fswork, 13);
        SYS_FS_FileClose(fileHandle);
        DBGprintf("%s 13 bytes written\n", fileName1);


    osDelayMs(2000);
    strcpy((char *)fswork, "xxxxxxxxxxxxx");
    fileHandle = SYS_FS_FileOpen(fileName1, (SYS_FS_FILE_OPEN_READ));
    fileSize = SYS_FS_FileSize(fileHandle);
    dbg_fileSize = fileSize;    // !dbg!
    if (dbg_fileSize > 1) {
        dbg_file_cntr++;
    }
    if (fileSize > 512) fileSize = 512;
    c = SYS_FS_FileRead(fileHandle, (void *)fswork, fileSize);
    SYS_FS_FileClose(fileHandle);
    DBGprintf("%s %d bytes read\n", fileName1, c);
    DBGprintf("%s", fswork);
    dump(fswork, fileSize);
    
    app_mem_read_dir();
    
    ////app_mem_file_write_ch("/mnt/mem1/text1.txt", dbg_str_1); 


    if (app_mem_file_exists("/mnt/mem1/text1.txt")) {
        dbg_file_cntr += 3;
    } else {
        dbg_file_cntr -= 4;
    }
    
    ////res = app_mem_file_app_ch("text1.txt", dbg_str_2); 
    ////dbg_res = res;
    
    dbg_file_cntr += 3;
    
    res = app_mem_file_write(fileName1, dbg_data_2, sizeof(dbg_data_2)); 
    dbg_res = res;
    
    res = app_mem_file_empty(fileName1);
    dbg_res = res;
    
    
    res = app_mem_file_app(fileName1, dbg_data_1, sizeof(dbg_data_1)); 
    dbg_res = res;
    res = app_mem_file_app(fileName1, dbg_data_1, sizeof(dbg_data_1)); 
    dbg_res = res;
    
    ////app_mem_file_read_ch("/mnt/mem1/text1.txt", dbg_str_X); 
    res = app_mem_file_read(fileName1, dbg_data_X, sizeof(dbg_data_X));
    dbg_res = res;
    
    dbg_file_cntr += 4;
    
    // read the file size back ....
    fileHandle = SYS_FS_FileOpen(fileName1, (SYS_FS_FILE_OPEN_READ));
    fileSize = SYS_FS_FileSize(fileHandle);
    dbg_fileSize = fileSize;    // !dbg!
    SYS_FS_FileClose(fileHandle);
    
    dbg_file_cntr += 14;
    
    // FILE 2 ..................................................................
    
    // Append data to file
    res = app_mem_file_app(fileName2, dbg_data_2, sizeof(dbg_data_2)); 
    dbg_res = res;
    res = app_mem_file_app(fileName2, dbg_data_1, sizeof(dbg_data_1)); 
    dbg_res = res;
    res = app_mem_file_app(fileName2, dbg_data_2, sizeof(dbg_data_2)); 
    dbg_res = res;

    // FILE 3 ..................................................................
    
    // Append data to file
    res = app_mem_file_app(fileName3, dbg_data_1, sizeof(dbg_data_1)); 
    dbg_res = res;
    res = app_mem_file_app(fileName3, dbg_data_2, sizeof(dbg_data_2)); 
    dbg_res = res;
    res = app_mem_file_app(fileName3, dbg_data_1, sizeof(dbg_data_1)); 
    dbg_res = res;

    app_mem_read_dir();

    
    res = app_mem_file_del(fileName2);
            
    app_mem_read_dir();
    
    // LARGE FILE ..............................................................

    res = app_mem_file_empty(fileName1);
    dbg_res = res;

    for (int i = 0; i < 4096; i++) {
        dbg_data_Big1[i] = i % 250;
        dbg_data_Big2[i] = 0;
    }
    res = app_mem_file_write(fileName1, dbg_data_Big1, sizeof(dbg_data_Big1)); 
    dbg_res = res;
            
    fileHandle = SYS_FS_FileOpen(fileName1, (SYS_FS_FILE_OPEN_READ));
    fileSize = SYS_FS_FileSize(fileHandle);
    dbg_fileSize = fileSize;    // !dbg!
    SYS_FS_FileClose(fileHandle);

    res = app_mem_file_read(fileName1, dbg_data_Big2, sizeof(dbg_data_Big2));
    dbg_res = res;
    
    */
    
    // Set up test data
    for (int i = 0; i < MEM_TEST_SIZE; i++) {
        dbg_data_Small_1[i] =  i % 18;
        dbg_data_Small_2[i] =  (i % 22) + 11;
    }
    


    // ---------------------------------
    // TEST 1
    // ---------------------------------

    // Clear read-back buffer, so check valid result
    for (int i = 0; i < MEM_TEST_SIZE; i++) {
        dbg_data_Small_3[i] = 0;
    }

    // Write first test buffer
    OS_SLEEP(10);
    dbg_mem_brk++;
    res = app_mem_file_app(fileName1, dbg_data_Small_1, sizeof(dbg_data_Small_1)); 
    dbg_res = res;
    if (dbg_res < 0) {
        dbg_mem_bad_cntr++;
    } else {
        dbg_mem_good_cntr++;
    }

    // See what files exist
    OS_SLEEP(10);
    dbg_mem_brk += 2;
    app_mem_read_dir();

    // Read back test data
    OS_SLEEP(10);
    dbg_mem_brk += 3;
    res = app_mem_file_read(fileName1, dbg_data_Small_3, sizeof(dbg_data_Small_3));
    dbg_res = res;
    if (dbg_res < 0) {
        dbg_mem_bad_cntr++;
    } else {
        dbg_mem_good_cntr++;
    }

    // Delete file
    OS_SLEEP(10);
    dbg_mem_brk += 4;
    dbg_mem_brk++;
    res = app_mem_file_del(fileName1);
    dbg_res = res;
    if (dbg_res < 0) {
        dbg_mem_bad_cntr++;
    } else {
        dbg_mem_good_cntr++;
    }

    dbg_mem_total_cntr++;

    OS_SLEEP(1000);

    // ---------------------------------
    // TEST 2
    // ---------------------------------

    // Clear read-back buffer, so check valid result
    for (int i = 0; i < MEM_TEST_SIZE; i++) {
        dbg_data_Small_3[i] = 0;
    }

    // Write first test buffer
    OS_SLEEP(10);
    dbg_mem_brk++;
    res = app_mem_file_app(fileName1, dbg_data_Small_2, sizeof(dbg_data_Small_2)); 
    dbg_res = res;
    if (dbg_res < 0) {
        dbg_mem_bad_cntr++;
    } else {
        dbg_mem_good_cntr++;
    }

    // See what files exist
    OS_SLEEP(10);
    dbg_mem_brk += 2;
    app_mem_read_dir();

    // Read back test data
    OS_SLEEP(10);
    dbg_mem_brk += 3;
    res = app_mem_file_read(fileName1, dbg_data_Small_3, sizeof(dbg_data_Small_3));
    dbg_res = res;
    if (dbg_res < 0) {
        dbg_mem_bad_cntr++;
    } else {
        dbg_mem_good_cntr++;
    }

    // Delete file
    OS_SLEEP(10);
    dbg_mem_brk += 4;
    dbg_mem_brk++;
    res = app_mem_file_del(fileName1);
    dbg_res = res;
    if (dbg_res < 0) {
        dbg_mem_bad_cntr++;
    } else {
        dbg_mem_good_cntr++;
    }

    dbg_mem_total_cntr++;

        
        while (1) {
            OS_SLEEP(1000);        
        }
}

// .............................................................................
