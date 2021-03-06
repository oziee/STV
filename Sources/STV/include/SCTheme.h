/*
 *  SCTheme.h
 *  Sensible TableView
 *
 *  Copyright 2011-2015 Sensible Cocoa. All rights reserved.
 *
 *
 */


#import <Foundation/Foundation.h>


/**
 The SCTheme class enables CSS-like styling of UIView (or any of its subclasses). Using CSS-like text files, any UIView property with a supported data type can be set. Key-path property format is fully supported (e.g. layer.cornerRadius: 5). All pointer data types accept nil as value (e.g. backgroundView: nil;).
 
 Supported property data types:
 
 Data Type   ->       Format in .sct file
 ---------            -------------------
 NSString*   ->       A string between single or double quotes.
 Example:
    detailTextLabel.text: "Hello World!";
 
 CGFloat     ->       A normal number.
 Example:
    height: 60;
 
 BOOL        ->       Possible values: TRUE, FALSE, YES, NO. All case insensitive.
 Example:
    clipsToBounds: NO;
 
 UIColor*    ->       Any UIColor color name constructor.
 Example:
    backgroundColor: blueColor;
 or                   rgb(redValue, greenValue, blueValue, optionalAlphaValue)
 Example:
    backgroundColor: rgb(100, 0, 255);
 or                   #hexValue
 Example:
    backgroundColor: #CC33FF
 or                   A string containing an image resource.
 Example:
    backgroundColor: "background.png";
 
 CGColorRef  ->       Format identical to UIColor.
 Example:
    layer.borderColor: redColor;
 
 CGRect      ->       CGRect(x, y, width, height)
 Example:
    textLabel.frame: CGRect(10, 10, 180, 30);
 
 CGSize      ->       CGSize(width, height)
 Example:
    textLabel.shadowColor: darkGrayColor;
    textLabel.shadowOffset: CGSize(1, 1);
 
 UIImage*    ->       A string containing the image resource.
 Example:
    backgroundImage: "background.png"
 or                   A string containing the image resource and capInsets(top, left, bottom, right).
 Example:
    backgroundImage: "background.png" capInsets(0,0,0,0)
 
 UIFont*     ->       Font name and size separated by a space. A good resource for font names is: http://iosfonts.com/
 Example:
    textLabel.font: Courier-Bold 12;
 
 UIView*     ->       A string containing an image resource that will be loaded into a UIImageView.
 Example:
    backgroundView: "background.png";
 
 UITableViewCellSeparatorStyle      Any valid UITableViewCellSeparatorStyle constant.
 Example: 
    separatorStyle: UITableViewCellSeparatorStyleNone;
 
 
 Sample theme file: MyTheme.sct
    UINavigationBar
    {
        backgroundImage: "navbar-background.png";
    }
  
    UITableView
    {
        backgroundView: "leather-background.png";
    }
 
    SCTableViewSection
    {
        firstCellThemeStyle: firstCell;
        oddCellsThemeStyle: oddCell;
        evenCellsThemeStyle: evenCell;
        lastCellThemeStyle: lastCell;
    }
 
    firstCell
    {
        backgroundView: "firstCell-background.png";
        selectedBackgroundView: "selectedFirstCell-background.png";
    }
 
    oddCell
    {
        backgroundView: "oddCell-background.png";
        selectedBackgroundView: "selectedOddCell-background.png";
    }
 
    evenCell
    {
        backgroundView: "evenCell-background.png";
        selectedBackgroundView: "selectedEvenCell-background.png";
    }
 
    lastCell
    {
        backgroundView: "lastCell-background.png";
        selectedBackgroundView: "selectedLastCell-background.png";
    }
 
 
 Sample code needed to use the above theme file:
    self.tableViewModel.theme = [SCTheme themeWithPath:@"MyTheme.sct"];
 */

@interface SCTheme : NSObject

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Creation and Initialization
//////////////////////////////////////////////////////////////////////////////////////////

/** Allocates and returns an initialized SCTheme given the path of the theme file. */
+ (instancetype)themeWithPath:(NSString *)path;

/** Returns an initialized SCTheme given the path of the theme file. */
- (instancetype)initWithPath:(NSString *)path;


//////////////////////////////////////////////////////////////////////////////////////////
/// @name Custom Styling
//////////////////////////////////////////////////////////////////////////////////////////

/** Styles the given object (typically a UIView subclass) using a style name provided in the theme's theme file. */
- (void)styleObject:(NSObject *)object usingThemeStyle:(NSString *)style;

/** 
 Styles the given object (typically a UIView subclass) using a style name provided in the theme's theme file, limiting the styled properties to the ones provided in propertyNames only. If propertyNames is nil, all object properties will be styled. 
 @note Naturally, properties in propertyNames will only be styled if they exist in the theme style.
 */
- (void)styleObject:(NSObject *)object usingThemeStyle:(NSString *)style onlyStylePropertyNamesInSet:(NSSet *)propertyNames;

@end
