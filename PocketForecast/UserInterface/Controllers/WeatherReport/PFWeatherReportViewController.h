////////////////////////////////////////////////////////////////////////////////
//
//  TYPHOON FRAMEWORK
//  Copyright 2013, Jasper Blues & Contributors
//  All Rights Reserved.
//
//  NOTICE: The authors permit you to use, modify, and distribute this file
//  in accordance with the terms of the license agreement accompanying it.
//
////////////////////////////////////////////////////////////////////////////////




#import <Foundation/Foundation.h>
#import "PFWeatherClient.h"
#import "PFWeatherReportViewDelegate.h"
#import "TyphoonComponentFactoryAware.h"

@class PFWeatherReport;
@protocol PFWeatherReportDao;
@protocol PFCityDao;
@class PFTheme;
@class TyphoonComponentFactory;


@interface PFWeatherReportViewController : UIViewController <PFWeatherReportViewDelegate, TyphoonComponentFactoryAware>
{

    PFWeatherReport* _weatherReport;
    NSString* _cityName;
    TyphoonComponentFactory* _factory;
}

#pragma mark - Spring injected via initializer
@property(nonatomic, strong, readonly) id <PFWeatherClient> weatherClient;
@property(nonatomic, strong, readonly) id <PFWeatherReportDao> weatherReportDao;
@property(nonatomic, strong, readonly) id <PFCityDao> cityDao;
@property(nonatomic, strong, readonly) PFTheme* theme;


- (id)initWithWeatherClient:(id <PFWeatherClient>)weatherClient weatherReportDao:(id <PFWeatherReportDao>)weatherReportDao
    cityDao:(id <PFCityDao>)cityDao theme:(PFTheme*)theme;


@end