import xml.etree.ElementTree as ET

def parse_srdf (packageName, srdf):
    from rospkg import RosPack
    import os
    rospack = RosPack()
    path = rospack.get_path(packageName)
    srdfFn = os.path.join(path, "srdf", srdf)

    # tree = ET.fromstring (srdfFn)
    tree = ET.parse (srdfFn)
    root = tree.getroot()
    grippers = []
    for xml in root.iter('gripper'):
        linksTag = xml.findall('link')
        if len(linksTag) != 1:
            raise Error ("Gripper needs exactly one tag link")
        jointsTag = xml.findall('joints')
        if len(jointsTag) > 1:
            raise Error ("Gripper needs at most one tag joints")
        elif len(jointsTag) == 1:
            joints = jointsTag[0].text.split()
        else:
            joints = tuple()
        positionsTag = xml.findall('position')
        if len(positionsTag) != 1:
            raise Error ("Gripper needs exactly one tag position")
        position = [ float(x) for x in positionsTag[0].text.split() ]
        g = { "name": str(xml.attrib['name']),
              "clearance": float(xml.attrib.get('clearance', 0)),
              "link": str(linksTag[0].attrib['name']),
              "position": tuple(position),
              "joints": joints
              }
        grippers.append (g)
    return grippers
