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

#ifndef HPP_MANIPULATION_SRDF_UTIL_HH
# define HPP_MANIPULATION_SRDF_UTIL_HH

# include <hpp/model/fwd.hh>
# include <hpp/manipulation/fwd.hh>

namespace hpp {
  namespace manipulation {
    namespace srdf {
      /// \note This function reads the following files:
      /// \li
      /// package://${modelName}_description/urdf/${modelName}${urdfSuffix}.urdf
      /// \li
      /// package://${modelName}_description/srdf/${modelName}${srdfSuffix}.srdf
      void loadEnvironmentModel (const DevicePtr_t& robot,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::vector<std::string>& srdfSuffixes);

      void loadEnvironmentModel (const DevicePtr_t& robot,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::string& srdfSuffix);

      /// \note This function reads the following files:
      /// \li
      /// package://${modelName}_description/urdf/${modelName}${urdfSuffix}.urdf
      /// \li
      /// package://${modelName}_description/srdf/${modelName}${srdfSuffix}.srdf
      void loadObjectModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::vector <std::string>& srdfSuffixes);

      void loadObjectModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::string& srdfSuffix);

      /// \note This function reads the following files:
      /// \li
      /// package://${modelName}_description/urdf/${modelName}${urdfSuffix}.urdf
      /// \li
      /// package://${modelName}_description/srdf/${modelName}${srdfSuffix}.srdf
      void loadHumanoidModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::vector <std::string>& srdfSuffixes);

      void loadHumanoidModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::string& srdfSuffix);

      /// \note This function reads the following files:
      /// \li
      /// package://${modelName}_description/urdf/${modelName}${urdfSuffix}.urdf
      /// \li
      /// package://${modelName}_description/srdf/${modelName}${srdfSuffix}.srdf
      void loadRobotModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::vector <std::string>& srdfSuffixes);

      void loadRobotModel (const DevicePtr_t& robot,
          const model::JointPtr_t& baseJoint,
          const std::string& prefix,
          const std::string& rootJointType,
          const std::string& package,
          const std::string& modelName,
          const std::string& urdfSuffix,
          const std::string& srdfSuffix);
    } // namespace srdf
  } // namespace manipulation
} // namespace hpp
#endif // HPP_MANIPULATION_SRDF_UTIL_HH
