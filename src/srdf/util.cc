// Copyright (c) 2014, LAAS-CNRS
// Authors: Joseph Mirabel (joseph.mirabel@laas.fr)
//
// This file is part of hpp-manipulation-urdf.
// hpp-manipulation-urdf is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-manipulation-urdf is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-manipulation-urdf. If not, see <http://www.gnu.org/licenses/>.

#include "hpp/manipulation/srdf/util.hh"

#include <hpp/model/urdf/util.hh>
#include <hpp/manipulation/device.hh>

#include "hpp/manipulation/parser/parser.hh"
#include "hpp/manipulation/srdf/factories/position.hh"

namespace hpp {
  namespace manipulation {
    namespace srdf {
      void loadEnvironmentModel (const DevicePtr_t& robot,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::string& srdfSuffix) {
        loadEnvironmentModel (robot, package, modelName, urdfSuffix,
            std::vector <std::string> (1, srdfSuffix));
      }

      void loadEnvironmentModel (const DevicePtr_t& robot,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::vector <std::string>& srdfSuffixes)
      {
        hpp::model::urdf::loadUrdfModel (robot, "anchor", package, modelName + urdfSuffix);

        for (std::size_t i = 0; i < srdfSuffixes.size (); ++i) {
          std::string srdfPath = "package://" + package + "/srdf/"
            + modelName + srdfSuffixes[i] + ".srdf";

          // Build robot model from URDF.
          parser::Parser handleParser;
          // For backward compatibility
          handleParser.addObjectFactory
            ("local_position", parser::create <PositionFactory>);

          handleParser.parse (srdfPath, robot);
        }
        hppDout (notice, "Finished parsing environment contacts.");
      }

      void loadObjectModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::string& srdfSuffix) {
        loadObjectModel (robot, baseJoint, prefix, rootJointType, package,
            modelName, urdfSuffix, std::vector <std::string> (1, srdfSuffix));
      }

      void loadObjectModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::vector <std::string>& srdfSuffixes)
      {
        hpp::model::urdf::loadRobotModel (robot, baseJoint, prefix,
            rootJointType, package, modelName, urdfSuffix, srdfSuffixes[0]);

        for (std::size_t i = 0; i < srdfSuffixes.size (); ++i) {
          std::string srdfPath = "package://" + package + "/srdf/"
            + modelName + srdfSuffixes[i] + ".srdf";

          // Build robot model from URDF.
          parser::Parser handleParser;
          // For backward compatibility
          handleParser.addObjectFactory ("local_position",
              parser::create <PositionFactory>);

          handleParser.prefix (prefix);
          handleParser.parse (srdfPath, robot);
        }
        hppDout (notice, "Finished parsing handles.");
      }

      void loadHumanoidModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::string& srdfSuffix) {
        loadHumanoidModel (robot, baseJoint, prefix, rootJointType, package,
            modelName, urdfSuffix, std::vector <std::string> (1, srdfSuffix));
      }

      void loadHumanoidModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::vector <std::string>& srdfSuffixes)
      {
        hpp::model::urdf::loadHumanoidModel (robot, baseJoint, prefix,
            rootJointType, package, modelName, urdfSuffix, srdfSuffixes[0]);

        for (std::size_t i = 0; i < srdfSuffixes.size (); ++i) {
          std::string srdfPath = "package://" + package + "/srdf/"
            + modelName + srdfSuffixes[i] + ".srdf";

          // Build robot model from URDF.
          parser::Parser gripperParser;
          // For backward compatibility
          gripperParser.addObjectFactory ("handle_position_in_joint",
              parser::create <PositionFactory>);

          gripperParser.prefix (prefix);
          gripperParser.parse (srdfPath, robot);
        }
        hppDout (notice, "Finished parsing grippers.");
      }

      void loadRobotModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::string& srdfSuffix) {
        loadRobotModel (robot, baseJoint, prefix, rootJointType, package,
            modelName, urdfSuffix, std::vector <std::string> (1, srdfSuffix));
      }

      void loadRobotModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::vector<std::string>& srdfSuffixes)
      {
        hpp::model::urdf::loadRobotModel (robot, baseJoint, prefix,
            rootJointType, package, modelName, urdfSuffix, srdfSuffixes[0]);

        for (std::size_t i = 0; i < srdfSuffixes.size (); ++i) {
          std::string srdfPath = "package://" + package + "/srdf/"
            + modelName + srdfSuffixes[i] + ".srdf";

          // Build robot model from URDF.
          parser::Parser gripperParser;
          // For backward compatibility
          gripperParser.addObjectFactory ("handle_position_in_joint",
              parser::create <PositionFactory>);

          gripperParser.prefix (prefix);
          gripperParser.parse (srdfPath, robot);
        }
        hppDout (notice, "Finished parsing grippers.");
      }
    } // namespace srdf
  } // namespace manipulation
} // namespace hpp
