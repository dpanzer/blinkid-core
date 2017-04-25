/**
 * @file BarcodeResult.h
 *
 * Copyright (c)2017 Microblink Ltd. All rights reserved.
 *
 * ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
 * OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
 * WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
 * UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
 * THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
 * REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
 */

#ifndef BARCODE_RESULT_INCLUDED
#define BARCODE_RESULT_INCLUDED

#include "Recognizer/Export.h"
#include "Recognizer/RecognizerError.h"
#include "Recognizer/RecognizerResultFwd.h"

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum BarcodeType
 * Possible types of barcodes.
 */
enum BarcodeType {
    /** Represents Aztec 2D barcode */
    BARCODE_TYPE_AZTEC,
    /** Represents Code 128 1D barcode */
    BARCODE_TYPE_CODE128,
    /** Represents Code 39 1D barcode */
    BARCODE_TYPE_CODE39,
    /** Represents DataMatrix 2D barcode */
    BARCODE_TYPE_DATA_MATRIX,
    /** Represents EAN 13 1D barcode */
    BARCODE_TYPE_EAN13,
    /** Represents EAN 8 1D barcode */
    BARCODE_TYPE_EAN8,
    /** Represents ITF 1D barcode */
    BARCODE_TYPE_ITF,
    /** Represents QR code */
    BARCODE_TYPE_QR,
    /** Represents UPC A 1D barcode */
    BARCODE_TYPE_UPCA,
    /** Represents UPC E 1D barcode */
    BARCODE_TYPE_UPCE,
    /** Represents PDF417 2D barcode */
    BARCODE_TYPE_PDF417,
    /** This is returned when result is not a barcode */
    BARCODE_TYPE_NOT_BARCODE
};

/**
 * @brief Typedef for BarcodeType enum.
 */
MB_EXPORTED_TYPE typedef enum BarcodeType BarcodeType;

/**
 * @brief Returns a string representation of BarcodeType enum. Returned pointer is a string constant.
 * @param bt BarcodeType value.
 * @return String representation of bt.
 */
MB_API const char* MB_CALL barcodeTypeToString( BarcodeType bt );

/**
 * @struct BarcodeResult
 * @brief Structure that holds result from scanning barcode.
 */
struct BarcodeResult {
    /** Type of barcode that was scanned */
    BarcodeType barcodeType;

    /** Whether or not scanned data is uncertain */
    int uncertain;

    /** Zero-terminated string of data inside scanned barcode. */
    const char* stringData;

    /** Zero-terminated extended string data - available only for Code39 1D barcode */
    const char* extendedStringData;

    /** Data inside barcode. Sometimes points to same memory address as stringData, but not always! */
    const void* rawData;

    /** Lenght of buffer to which rawData points */
    size_t rawDataSize;
};

/**
 * @brief Typedef for BarcodeResult structure.
 */
MB_EXPORTED_TYPE typedef struct BarcodeResult BarcodeResult;

/**
 * @memberof RecognizerResult
 * @brief Returns the result of the scanned barcode. Use this method if either recognizerResultIsPdf417Result, recognizerResultIsBardecoderResult or recognizerResultIsZXingResult return non-zero value.
 * NOTE: Method does not work with results generated by US Driver's License recognizer (RECOGNIZER_ERROR_STATUS_INVALID_ARGUMENT is returned). To
 * obtain raw USDL string data, use recognizerResultGetUSDLRawStringData
 * @param result RecognizerResult object.
 * @param barcodeResult pointer to BarcodeResult structure that will be filled with data from scanned barcode. All pointers within the structure will be valid until recognizerResultDelete is called on the 'result' object.
 * @return status of the operation
 */
MB_API RecognizerErrorStatus MB_CALL recognizerResultGetBarcodeResult(const RecognizerResult* result, BarcodeResult* barcodeResult);

#ifdef __cplusplus
}
#endif

#endif
