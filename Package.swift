// swift-tools-version: 6.3

//===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===//
//
//  Package.swift
//  nio-framework
//
//  Created by Fang Ling on 2026/6/21.
//
//  This source file is part of the NIOFramework open source project
//
//  Copyright (c) 2026 Fang Ling <fangling@fangl.ing>
//  Licensed under Apache License v2.0
//
//  See LICENSE for license information
//
//  SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===//

import PackageDescription

let package = Package(
  name: "nio-framework",
  products: [
    .library(name: "NIOFramework", targets: ["NIOFramework"]),
  ],
  dependencies: [
    .package(path: "../c-framework"),
    .package(path: "../foundation-framework"),
    .package(path: "../objective-c-framework"),
    .package(path: "../testing-framework")
  ],
  targets: [
    .target(
      name: "NIOFramework",
      dependencies: [
        .product(name: "CFramework", package: "c-framework"),
        .product(name: "FoundationFramework", package: "foundation-framework"),
        .product(name: "ObjectiveCFramework", package: "objective-c-framework")
      ],
      publicHeadersPath: "Includes"
    ),
    .testTarget(
      name: "NIOFrameworkTests",
      dependencies: [
        "NIOFramework",
        .product(name: "TestingFramework", package: "testing-framework")
      ]
    )
  ]
)
