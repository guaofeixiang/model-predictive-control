/* Auto-generated by genmsg_cpp for file /home/cmastalli/ros_workspace/model-predictive-control/ardrone_mpc/msg/Reference.msg */
#ifndef ARDRONE_MPC_MESSAGE_REFERENCE_H
#define ARDRONE_MPC_MESSAGE_REFERENCE_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"

namespace ardrone_mpc
{
template <class ContainerAllocator>
struct Reference_ {
  typedef Reference_<ContainerAllocator> Type;

  Reference_()
  : header()
  , reference_states()
  {
  }

  Reference_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , reference_states(_alloc)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _reference_states_type;
  std::vector<double, typename ContainerAllocator::template rebind<double>::other >  reference_states;


  typedef boost::shared_ptr< ::ardrone_mpc::Reference_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ardrone_mpc::Reference_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Reference
typedef  ::ardrone_mpc::Reference_<std::allocator<void> > Reference;

typedef boost::shared_ptr< ::ardrone_mpc::Reference> ReferencePtr;
typedef boost::shared_ptr< ::ardrone_mpc::Reference const> ReferenceConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::ardrone_mpc::Reference_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::ardrone_mpc::Reference_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace ardrone_mpc

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::ardrone_mpc::Reference_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::ardrone_mpc::Reference_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::ardrone_mpc::Reference_<ContainerAllocator> > {
  static const char* value() 
  {
    return "e7a43d6f744e20788df3b315da1559c4";
  }

  static const char* value(const  ::ardrone_mpc::Reference_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xe7a43d6f744e2078ULL;
  static const uint64_t static_value2 = 0x8df3b315da1559c4ULL;
};

template<class ContainerAllocator>
struct DataType< ::ardrone_mpc::Reference_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ardrone_mpc/Reference";
  }

  static const char* value(const  ::ardrone_mpc::Reference_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::ardrone_mpc::Reference_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
# Syntax: [x, y, z, yaw, vx, vy, vz, vyaw]\n\
float64[] reference_states\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::ardrone_mpc::Reference_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::ardrone_mpc::Reference_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::ardrone_mpc::Reference_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::ardrone_mpc::Reference_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.reference_states);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Reference_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ardrone_mpc::Reference_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::ardrone_mpc::Reference_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "reference_states[]" << std::endl;
    for (size_t i = 0; i < v.reference_states.size(); ++i)
    {
      s << indent << "  reference_states[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.reference_states[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // ARDRONE_MPC_MESSAGE_REFERENCE_H

