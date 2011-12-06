//
//  Sampler.h
//  Carat
//
//  Created by Anand Padmanabha Iyer on 11/5/11.
//  Copyright (c) 2011 UC Berkeley. All rights reserved.
//

#ifndef Carat_Sampler_h
#define Carat_Sampler_h

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <mach/mach_host.h>
#import "Globals.h"
#import "UIDeviceProc.h"
#import "CoreDataProcessInfo.h"
#import "CoreDataSample.h"
#import "CommunicationManager.h"

@interface Sampler : NSObject {
    CommunicationManager * commManager;
}

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (nonatomic, retain) NSFetchedResultsController *fetchedResultsController;

- (id) initWithCommManager : cManager;
- (void) sampleNow : (NSString *) triggeredBy;
- (void) fetchAndSendSamples : (NSUInteger) limitSamplesTo;
- (NSURL *) applicationDocumentsDirectory;

@end

#endif