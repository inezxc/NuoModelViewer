//
//  NuoRayTracingAccelerateStructure.h
//  ModelViewer
//
//  Created by middleware on 6/16/18.
//  Copyright © 2018 middleware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

#include "NuoMathVector.h"


extern const uint kRayIntersectionStrid;


@class NuoMesh;
@class NuoRenderPassTarget;


@interface NuoRayAccelerateStructure : NSObject


@property (nonatomic, assign) CGFloat fieldOfView;
@property (nonatomic, assign) CGSize drawableSize;

@property (nonatomic, readonly) id<MTLBuffer> primaryRayBuffer;


- (instancetype)initWithQueue:(id<MTLCommandQueue>)queue;

- (void)setMeshes:(NSArray<NuoMesh*>*)meshes;
- (void)setView:(const NuoMatrixFloat44&)viewTrans;

- (void)rayTrace:(id<MTLCommandBuffer>)commandBuffer
        inFlight:(uint32_t)inFlight withIntersection:(id<MTLBuffer>)intersection;
- (void)rayTrace:(id<MTLCommandBuffer>)commandBuffer
        withRays:(id<MTLBuffer>)rayBuffer withIntersection:(id<MTLBuffer>)intersection;


- (id<MTLBuffer>)uniformBuffer:(uint32_t)inFlight;


@end


